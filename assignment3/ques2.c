#include<pthread.h>

pthread_t tid;

void* thread1(void *arg)
{
	printf("newly created thread executing\n");
	while(1);
}

int main(void)
{
	int ret = pthread_create(&tid,NULL,thread1,NULL);
	int t=0;

	printf("Thread id: %u\n",tid);
	sleep(6);

	t=pthread_cancel(tid);

	if(t==0)
		printf("cancel thread\n");

	printf("Thread id: %u\n",tid);

//	sleep(2);
	//pthread_join(tid,NULL); //make parent to wait to execute 
	return 0;
}

