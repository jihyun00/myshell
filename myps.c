#include <stdio.h>
#include <stdlib.h>

void input(int, char **);

void myps(int size, char **argv) {
	if(size == 1) {
			

		return;
	}
}

void input(int s, char **in) {
	int i;
	for(i = 0; i < s; i++) {
		printf("%s ", in[i]);
	}
}
