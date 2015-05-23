#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

void myrm(char **argv) {
	int err;

	if(sizeof(argv) == 1) {
		err = unlink(argv[0]);
		if(err == -1) {
			printf("%s\n", strerror(errno));
		}

	} else if(sizeof(argv) == 2) {

	} else {
		// ERROR
	}

}
