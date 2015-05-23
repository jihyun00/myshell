#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

void myrmdir(char **argv) {
	int err;

	if(sizeof(argv[0]) == 1) {
		err = rmdir(argv[0]);	
		if(err == -1) {
			printf("%s\n", strerror(errno));
		}

	} else {
		// ERROR
	}
}
