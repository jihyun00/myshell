#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char *extraction(char *command) {
	char *path;
	char *pathes = getenv("PATH");
	int existing; 
	
	path = strtok(pathes, ":");
	while(path = strtok(NULL, ":")) {
		if(existing = (access(command, R_OK)) != -1) {
			strcat(path, '/');
			strcat(path, command);
			return path;
		}
	}
	
	return NULL;
}
