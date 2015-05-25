#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

void mycp(int size, char **argv) {
	int ofd, nfd;
	int old, new;
	char buf[256];
	char *reverse;
	char *source;
	char *dest;

	if(size == 2) {
		if(strcmp(argv[1], "--help") == 0) {
			// USAGE		
		} else {
			// invalid command
		}
	} else if(size == 3) {
		source = argv[1];
		dest = argv[2];

	} else if(size == 4) {
		source = argv[2];
		dest = argv[3];

	} else {
		// ERROR
	} 

	ofd = open(source, O_RDONLY);
	if(ofd == -1) {
		perror("open");
		return;
	}
	old = read(ofd, buf, sizeof(buf));
	if(old == -1) {
		perror("read");
		return;
	}
	buf[old] = '\0';

	if(size == 4) {
		if(strcmp(argv[1], "-reverse") == 0) {
			int i = 0;
			int j;
			reverse = (char *)malloc(strlen(buf));
				for(j = strlen(buf)-1; j > 0; j--) {
					reverse[i++] = buf[j];
				}
			printf("%s\n", reverse);
			strcpy(buf, reverse);
		} else {
			// ERROR
		}
	}

	int acc;
	if(acc = (access(dest, F_OK)) == -1) {
		nfd = open(dest, O_CREAT | O_WRONLY, 0644);
	} else if(acc == 0) {
		nfd = open(dest, O_WRONLY | O_TRUNC);
	}
	if(nfd == -1) {
		perror("open");
		return;
	}

	if(write(nfd, buf, strlen(buf)) != strlen(buf)) {
		perror("write");
		return;
	}

	close(ofd);
	close(nfd);
}
