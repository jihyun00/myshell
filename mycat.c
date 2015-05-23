#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

void mycat(char **argv) {
	char buf[256];
	char *filename = argv[0];	
	int fd, n, len;

	if(sizeof(argv) == 1) {
		len = sizeof(buf);
	} else if(sizeof(argv) == 2) {
		len = argv[1];
	} else {
		// Usage Error
	}

	fd = open(filename, O_RDONLY);
	n = read(fd, buf, len);
	if(n == -1) {
		perror("read");
		exit(1);
	}

	buf[n] = '\0';

	close(fd);

	printf("%s\n", buf);
}
