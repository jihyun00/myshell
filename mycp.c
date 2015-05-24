#include <stdio.h>
#include <stdlib.h>

void mycp(int size, char **argv) {
	int ofd, nfd;
	int old, new;
	char buf[256];
	char *reverse;

	ofd = open(argv[1], O_RDONLY);
	if(ofd == -1) {
		perror("open");
		exit(1);
	}
	old = read(ofd, buf, sizeof(buf));
	if(old == -1) {
		perror("read");
		exit(1);
	}

	if(sizeof(argv) == 3) {
		if(strcmp(argv[0], "-reverse") == 0) {
			int i, j;
			reverse = (char *)malloc(strlen(buf));
			for(i = 0; i < strlen(buf); i++) {
				for(j = strlen(buf); j > 0; j--) {
					reverse[j] = buf[i];
				}
			}
			strcpy(buf, reverse);
		} else {
			// ERROR
		}
	}

	nfd = open(argv[1], O_WRONLY | O_TRUNC);
	if(nfd == -1) {
		perror("open");
		exit(1);
	}

	if(write(nfd, buf, sizeof(buf) != sizeof(buf))) {
		perror("write");
		exit(1);
	}

	close(ofd);
	close(nfd);
}
