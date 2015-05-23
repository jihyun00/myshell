#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void cd(char **argv) {
	if(sizeof(argv) == 1) {
		chdir(argv[0]);

	} else if(sizeof(argv) == 2) {

	}
}
