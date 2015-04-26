#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "extraction.h"

#define BUFSIZE 4096
#define PATH_MAX 1024

typedef enum {false, true} bool; //define boolean type

int main() {
	while(1) {
		pid_t pid;
		int status;
		char buf[BUFSIZE];
		char *token;
		int count = 2;
		bool inputNeed = false;
		FILE *inputFile;
		int bgOption = 0;

		char *currentPath = getenv("PWD"); //get current directory path
		char *currentDir; //extract only directory name
		char *newToken = strtok(currentPath, "/");
		int tokenIndex = 0;
		while(newToken = strtok(NULL, "/")) {
			currentDir = newToken;		
		}

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

		int i = 0;
		while(token = strtok(NULL, " ")) {
			if(strcmp(token, ">") == 0) {
				inputNeed = true;

			} else if(strcmp(token, "<") == 0) {
				inputNeed = true;

			} else if(strcmp(token, "|") == 0) {
				continue;

			} else if(strcmp(token, "~") == 0) {
				char *homePath = getenv("HOME"); //get home path	
				paramList[++i] = homePath;

			} else {
				if(inputNeed) { //when met >

				} else if(inputNeed) {//when met <

				} else {
					paramList[++i] = token;
				}
			}
		}

		paramList[i+1] = NULL; //add null pointer

		char *binPath = existing(paramList[0]);

		if((pid = fork()) < 0) { //error handling
			printf("fork error\n");
			exit(1);
		} else if(pid == 0) { //child process
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
