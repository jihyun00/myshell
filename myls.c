#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

void myls(char **argv) {
	struct dirent *dent;
	DIR *dp;
	// 아무 인자도 받지 않았을 경우
	if(argv == NULL) {
		if((dp = opendir("./")) == NULL) {
			exit(1);
		}

		while((dent = readdir(dp)) != NULL) {
			printf("%s\t", dent->d_name);
		}
		printf("\n");

	} else {	
		

	}
	
}
