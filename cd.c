#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void cd(char **argv) {
	//TODO: move before path
	if(sizeof(argv) == 1) {
		int fd, n;
		char *buf, *token, *content;

		if(access(dir[index], F_OK) == -1) {
			fd = open("./history.txt", O_CREAT | O_RWDR);
		} else {
			fd = open("./history.txt", O_RWDR);
		}

		if(strcmp(argv[0], "~") == 0) { // TODO : 이거 필요없을지도..
			char *homePath = getenv("HOME"); //get home path	
			chdir(homePath);
		}

		chdir(argv[0]);

		n = read(fd, content, sizeof(content));
		if(n == -1) {
			perror("read");
			exit(1);
		}
		content[n] = '\0';

		token = strtok(content, "/");
		while(token != NULL) { //check saved path count
			index++;
			token = strtok(NULL, "/");
		}

		if(index > 50) { // if count is over 50, exit
			return;
		}

		sprintf(buf, "/%s", argv[0]);

		if(write(fd, buf, sizeof(buf)) != sizeof(buf)) {
			perror("write");
			return;
		}

	} else if(sizeof(argv) == 2) {
		if(strcmp(argv[0], "-b")== 0) {
			int i, num;
			num = atoi(argv[1]);

			if(num < 0) {
				printf("Invalid Value\n");
				return;
			}

		} else {
			printf("Invalid Option\n");
			return;
		}
	}
}
