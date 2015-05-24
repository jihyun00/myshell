#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

void myls(char **argv) {
	struct dirent *dent;
	DIR *dp;

	if((dp = opendir("./")) == NULL) {
		exit(1);
	}

	while((dent = readdir(dp)) != NULL) {
		printf("%s\t", dent->d_name);
	}
	printf("\n");
}
