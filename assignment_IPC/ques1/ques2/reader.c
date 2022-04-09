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
	
	msgctl(id, IPC_STAT, &mybuff);


	// printing contents of message queue through struct msgid_ds

	printf("Contents from the struct are ..... \n");
	printf("No. of messages in queue: %d\n",mybuff.msg_qnum);
	printf("No. of bytes in queue: %d\n",mybuff.msg_cbytes);
	printf("Max No. of bytes in queue: %hi\n",mybuff.msg_qbytes);
	
	printf("\n----------------------------------------------------------------\n");
	
	msgrcv(id, &m1, sizeof(m1), 1, 0);

	printf("Msg Type is --> %ld\n",m1.mytype);
	printf("Message is --> %s\n",m1.data);
	
	msgctl(id, IPC_RMID, NULL);
	
	return 0;
	
}
