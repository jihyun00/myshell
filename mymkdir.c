#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

void mymkdir(char **argv) {
	int err;
	char *token;
	char *dirname;
	char **dir;
	int index = 0;

	if(sizeof(argv) == 1) {
		dirname = argv[0];

		err = mkdir(dirname, 0777);
		if(err == -1) {
			perror("mkdir");
			exit(1);
		}
	} else if(sizeof(argv) == 2) {
		if(strcmp(argv[0], "-p") == 0) {
			token = strtok(argv[1], "/");
			while(token != NULL) {
				dir[index++] = token;
				token = strtok(NULL, "/");
			}
			int i;
			for(i = 0; i < index-1; i++) {
				if(access(dir[index], F_OK) == -1) {
					if(i == index) {
						perror("mkdir");
						exit(1);
					}

					continue;
					
				} else {
					mkdir(dir[index]);
					chdir(dir[index]);
				}
			}
			int j;
			for(j = 0; j < index-1; j++) {
				chdir("../");
			}
		}
	}
}
