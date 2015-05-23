#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void mymkdir(char **argv) {
	int err;

	if(sizeof(argv) == 1) {
		char *dirname = argv[0];

	} else if(sizeof(argv) == 2) {
		if(strcmp(argv[0], "-p") == 0) {
			dirname = argv[1];
			// 고민해보기
		} else {
			// ERROR
		}

	} else {
		//ERROR
	}

	err = mkdir(dirname, 0777);
	if(err == -1) {
		perror("mkdir");
		exit(1);
	}
}
