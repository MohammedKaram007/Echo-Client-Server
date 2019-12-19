/*
 * echoclient.c - An echo client
 */
/* $begin echoclientmain */
#include "csapp.h"

int main(int argc, char **argv)
{

char c;
size_t n;
int fd1 , fd4;


fd1 = Open("firstFile.txt", O_RDWR|O_CREAT|O_TRUNC, S_IRUSR|S_IWUSR);
fd4 = Open("forthFile.txt", O_RDWR|O_CREAT|O_TRUNC, S_IRUSR|S_IWUSR);

    int clientfd;
    char *host, *port, buf[MAXLINE];

    if (argc != 3) {
	fprintf(stderr, "usage: %s <host> <port>\n", argv[0]);
	exit(0);
    }
    host = argv[1];
    port = argv[2];

    clientfd = Open_clientfd(host, port);
	fd1 = Open("firstFile.txt", O_CREAT|O_TRUNC|O_RDWR, DEF_MODE);

    while ((n=read(STDIN_FILENO, &buf, MAXLINE)) != 0) {
	write(fd1, &buf, n);
	read (fd1, &buf, MAXLINE);

	write(clientfd, &buf, n);
	n=read(clientfd, &buf, MAXLINE);
	fd4 = Open("forthFile.txt", O_CREAT|O_TRUNC|O_RDWR, DEF_MODE);
	write(fd4, &buf, n);
	write(STDIN_FILENO, &buf, n);
    }
    Close(clientfd); //line:netp:echoclient:close
    Close (fd1);
    Close (fd4);
    exit(0);
}
/* $end echoclientmain */
