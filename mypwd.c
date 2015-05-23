#include <stdio.h>
#include <stdlib.h>

void mypwd() {
	char *currentPath = malloc(2048);

	if(getcwd(currentPath, PATH_MAX) == NULL) {
		perror("getcwd");
	}

	printf("%s\n", currentPath);
}
