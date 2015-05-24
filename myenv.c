#include <stdio.h>
#include <stdlib.h>

extern char **environ;

void myenv(char **argv) {
	if(strcmp(argv[0], "")) {
		int i;
		char *env = *environ;

		while(env) {
			printf("%s\n", env);
			env = *(environ+i);
			i++;
		}
	} else {	
		printf("%s\n", getenv(argv[0]));
	}
}
