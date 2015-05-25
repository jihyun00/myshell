CC=gcc
CFLAGS=
OBJS=mysh.o extract.o myenv.o mypwd.o myls.o mycat.o mycp.o mymkdir.o myrmdir.o
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

myls.o: myls.c
	$(CC) $(CFLAGS) -c myls.c

mycat.o: mycat.c
	$(CC) $(CFLAGS) -c mycat.c

mycp.o: mycp.c
	$(CC) $(CFLAGS) -c mycp.c

mymkdir.o: mymkdir.c
	$(CC) $(CFLAGS) -c mymkdir.c

myrmdir.o: myrmdir.c
	$(CC) $(CFLAGS) -c myrmdir.c

clean:
	rm -rf $(RUN_NAME)
	rm -rf $(OBJS)
