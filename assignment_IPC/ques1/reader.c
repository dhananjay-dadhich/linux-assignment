#include<stdio.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/shm.h>

#define MY_SHM_KEY 48

int main()
{
	char *data;
	int id;
	
	id = shmget(MY_SHM_KEY, 250, IPC_CREAT|0644);
	
	if(id<0)
	{
		perror("shmget");
		exit(1);
	}
	
	printf("shared memory id --> %d\n", id);
	data = shmat(id, 0, 0);
	printf("data --> %s\n", data);
	
	
	return 0;
  
}
