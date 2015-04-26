#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char *extraction(char *command) {
	int leng;
	int existing;
	char *file_path;
	char *pathes;

	existing = -1;
	pathes = (char *)malloc(strlen(getenv("PATH"))*sizeof(char));
	strcpy(pathes, getenv("PATH"));

	char *path = strtok(pathes, ":");
	while(path = strtok(NULL, ":")) {
		leng = strlen(command) + strlen(path)+1;
		file_path = (char *)malloc(leng * sizeof(char));

		strncpy(file_path, path, strlen(path)*sizeof(char));
		strcat(file_path, "/");
		strcat(file_path, command);

		existing = access(file_path, R_OK);
		if(existing == 0) {
			break;
		}
	
	}

	free(pathes);

	if(existing == 0) {
		return file_path;

	} else {
		return NULL;
	}
}
