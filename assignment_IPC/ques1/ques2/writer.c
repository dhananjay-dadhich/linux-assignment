#include<stdio.h>
#include<sys/msg.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>

#define MY_KEY 55

struct msg_buf
{
	long mtype;
	char buff[512];
};



int main()
{
	struct msg_buf m1;
	struct msqid_ds mybuff;



	int id;
	

	id = msgget(MY_KEY, IPC_CREAT|0644);
	
	if(id < 0)
	{
		perror("msgget");
		exit(1);
	}



	printf("Id of message queue: %d\n",id);
	
	m1.mtype = 1;
	strcpy(m1.buff, "Hey, This is a demo message to test message queue");



	msgsnd(id, &m1, strlen(m1.buff) +1, 0);
	perror("msgsnd m1");

	msgctl(id, IPC_STAT, &mybuff);



	// printing contents of message queue through struct msgid_ds

	printf("Contents from the struct are ..... \n");
	printf("No. of messages in queue: %d\n",mybuff.msg_qnum);
	printf("No. of bytes in queue: %d\n",mybuff.msg_cbytes);
	printf("Max No. of bytes in queue: %hi\n",mybuff.msg_qbytes);




	return 0;
}
