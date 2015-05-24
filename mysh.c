#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "extract.h"
#include "mycommand.h"

#define BUFSIZE 4096
#define PATH_MAX 1024

int main() {
	while(1) {
		pid_t pid;
		int status;
		int count;
		char buf[BUFSIZE];
		char *token;
		char *redirection;
		int bgOption = 0;
		char *fileName;
		int fd;

		char *currentDir = getCurrentDir();

		printf("[20122301 %s]$ ", currentDir);
		fgets(buf, BUFSIZE, stdin);

		if(strlen(buf) != 1) {
			buf[strlen(buf)-1] = '\0'; //remove \n
		} else { //when I received enter, ignore it.
			continue;
		}

		int final = strlen(buf)-1;
		if(buf[final] == '&') { //execute background working
			bgOption = WNOHANG;	
			buf[final]= '\0';
		}

		char **paramList;
		int index = 0;

		token = strtok(buf, " ");
		while(token != NULL) {
			paramList[index++] = token;
			token = strtok(NULL, " ");
		}

		if(strcmp(paramList[0], "exit") == 0) {
			exit(0);

		} else if(strcmp(paramList[0], "myenv") == 0) {
			myenv(index, paramList);

		} else if(strcmp(paramList[0], "mypwd") == 0) {
			mypwd(index, paramList);

		} else if(strcmp(paramList[0], "mycat") == 0) {
			mycat(index, paramList);

		}

		/*if(waitpid(pid, &status, bgOption) == -1) {
				printf("wait error\n");
				exit(1);
			} else {
				if(bgOption == WNOHANG) {
					printf("[1] %d\n" ,pid);
				}
			}
		}*/
	}

	return 0;
}
