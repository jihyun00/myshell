CC=gcc
CFLAGS=
OBJS=mysh.o extract.o myenv.o mypwd.o
RUN_NAME=mysh

all: add

add: $(OBJS)
	$(CC) $(CFLAGS) -o $(RUN_NAME) $(OBJS) $(LIBS)

mysh.o: mysh.c
	$(CC) $(CFLAGS) -c mysh.c

extract.o: extract.c
	$(CC) $(CFLAGS) -c extract.c

myenv.o: myenv.c
	$(CC) $(CFLAGS) -c myenv.c

mypwd.o: mypwd.c
	$(CC) $(CFLAGS) -c mypwd.c

clean:
	rm -rf $(RUN_NAME)
	rm -rf $(OBJS)
