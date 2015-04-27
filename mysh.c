#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "extract.h"

#define BUFSIZE 4096
#define PATH_MAX 1024

int main() {
	while(1) {
		pid_t pid;
		int status;
		char buf[BUFSIZE];
		char *token;
		int count = 2;
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

		int index;
		for(index = 0; index < strlen(buf); index++) {
			if(buf[index] == ' ') {
				count++;
			}
		}

		int final = strlen(buf)-1;
		if(buf[final] == '&') { //execute background working
			bgOption = WNOHANG;	
			buf[final]= '\0';
		}

		char *paramList[count];

		token = strtok(buf, " "); //split input string to whitespace
		paramList[0] = token;

		if(strcmp(paramList[0], "exit") == 0) {
			exit(0);
		}


		int i = 0;
		redirection = ""; //initialize redirection value
		while(token = strtok(NULL, " ")) {
			if(strcmp(token, ">") == 0 || strcmp(token, "<") == 0 || strcmp(token, "|") == 0) {
				redirection = malloc((strlen(token)+1)*sizeof(char));
				redirection = token;

			} else if(strcmp(token, "~") == 0) {
				char *homePath = getenv("HOME"); //get home path	
				paramList[++i] = homePath;

			} else {
				if(strlen(redirection) != 0) {
					fileName = token;

				} else {
					paramList[++i] = token;
				}
			}
		}

		paramList[i+1] = NULL; //add null pointer

		char *binPath = extraction(paramList[0]); //get path environment

		if((pid = fork()) < 0) { //error handling
			printf("fork error\n");
			exit(1);
		} else if(pid == 0) { //child process
			if(strlen(redirection) != 0) {
				if(strcmp(redirection, ">") == 0) {
					fd = open(fileName, O_WRONLY | O_TRUNC);
					if(fd == -1) {
						printf("open() error\n");
						exit(1);
					}

					dup2(fd, STDOUT_FILENO);

				} else if(strcmp(redirection, "<") == 0) {
					fd = open(fileName, O_RDONLY);
					if(fd == -1) {
						printf("open() error\n");
						exit(1);
					}

					dup2(fd, STDIN_FILENO);

				} else { //when redirection is pipe

				}

				close(fd);
			}

			if(execv(binPath, paramList) == -1) {
				printf("execv error\n");
				exit(1);
			}
		} else { //parent process
			if(waitpid(pid, &status, bgOption) == -1) {
				printf("wait error\n");
				exit(1);
			} else {
				if(bgOption == WNOHANG) {
					printf("[1] %d\n" ,pid);
				}
			}
		}
	}

	return 0;
}
