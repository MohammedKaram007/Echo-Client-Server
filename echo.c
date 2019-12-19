#include "csapp.h"

void echo(int connfd)
{
	char c;
 	int fd2, fd3;
	size_t n;
	char buf[MAXLINE];


	while((n = read(connfd, &buf, MAXLINE)) != 0) {
	fd2 = Open("secondFile.txt" , O_RDWR|O_CREAT|O_TRUNC, DEF_MODE );
	fd3 = Open("thirdFile.txt" , O_RDWR|O_CREAT|O_TRUNC, DEF_MODE );
		printf("server received %d bytes\n", (int)n);
		Write(fd2, &buf, n);
		
	

	fd2 = Open("secondFile.txt" , O_RDWR|O_CREAT, DEF_MODE );

	int firstStar  = 0 , lastStar = 0 ;

	while(Read(fd2 , &c , 1) != 0){
		if (c == '*' && firstStar == 0  ){
			firstStar = 1 ; 
			continue ; 
		}

		if (c == '*' && firstStar  == 1 ){
			break;   
		}

		if (firstStar == 1){
			Write(fd3 , &c , 1);
		}
	}

	Close(fd2);
	Close(fd3);

	fd3 = Open("thirdFile.txt" , O_RDWR|O_CREAT, DEF_MODE);
	n = Read(fd3, &buf, MAXLINE);
		Write (connfd,&buf,n);
	Close(fd3);
}
	exit(0);
}

