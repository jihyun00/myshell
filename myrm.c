#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

void input(int s, char **in);

void myrm(int size, char **argv) {
	if(size == 2) {
		if(strcmp(argv[1], "--help") == 0) {
			printf("myrm command delete file\n");
			printf("usage : myrm [-rf] [FILENAME]\n");
			printf("[option] -- help : print myrm command usage\n\t-rf : delete file or directory forcely\n");

			return;
		} else {
			int err;

			err = unlink(argv[1]);
			if(err == -1) {
				input(size, argv);
				printf(": %s\n", strerror(errno));

				return;
			}
		}
	} else if(size == 3) {
		if(strcmp(argv[1], "-rf") == 0) {

		} else {
			input(size, argv);
			printf(": Invalid option\n");

			return;
		}
	}
}

void input(int s, char **in) {
	int i;
	for(i = 0; i < s; i++) {
		printf("%s ", in[i]);
	}
}
