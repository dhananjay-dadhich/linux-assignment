#include<stdio.h>
#include<sys/ipc.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>

int fd[2];


void parent_code()
{
	char *wbuf1 = "this is write buffer 1...";
	char *wbuf2 = "this is write buffer 2...";
	
	close(fd[0]);
	
	write(fd[1], wbuf1, 25);
	write(fd[1], wbuf2, 25);
	
	printf(" end of parent\n");
	
}


void child_code()
{
	char *buf[100];
	int n, i;
	
	close(fd[1]);
	
	n = read(fd[0], buf, 100);
	printf("No of char read : %d\n", n);
	
	
	for(i = 0;i<n;i++)
	{
		printf("%c", buf[i]);
	}
	
	printf(" end of child\n");
}


int main()
{
	
	int res, i;
	
	
	pid_t pid1;
	
	res = pipe(fd);
	
	if(res == -1)
	{
		fprintf(stderr, "pipe not created\n");
		return 0;
	}
	
	
	pid1 = fork();
	
	
	if(pid1 == 0)
	{
		child_code();		//child reading from pipe
	}
	
	else
	{
		parent_code();		//parent writing to pipe
	}
	
	printf("\n");


	return 0;
}
