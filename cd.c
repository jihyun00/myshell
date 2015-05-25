#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

void cd(int size, char **argv) {
	//TODO: move before path
	if(size == 2) {
		int fd, n;
		char *buf, *token, *content;

		int index = 0;
		if(access("./history.txt", F_OK) == -1) {
			fd = open("./history.txt", O_CREAT | O_RDWR);
		} else {
			fd = open("./history.txt", O_RDWR);
		}

		if(strcmp(argv[1], "~") == 0) {
			char *homePath = getenv("HOME"); //get home path	
			chdir(homePath);
		}

		chdir(argv[1]);

		n = read(fd, content, sizeof(content));
		if(n == -1) {
			perror("read");
			return;
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

		sprintf(buf, "/%s", argv[1]);

		if(write(fd, buf, sizeof(buf)) != sizeof(buf)) {
			perror("write");
			return;
		}

	} else if(size == 3) {
		if(strcmp(argv[1], "-b")== 0) {
			int i, num;
			num = atoi(argv[2]);

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
