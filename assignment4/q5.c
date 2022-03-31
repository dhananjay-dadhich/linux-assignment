#define _xopen_source 600
#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<sys/types.h>
#include<bits/types.h>
#include<unistd.h>
#include<errno.h>

static pthread_spinlock_t spinlock;
volatile int slock;

void *spinlockThread(void *i)
{
	int    rc;
	int    count=0;
	
	printf("Entered thread %d,getting Spin lock \n",(int *)i);
	
	rc = pthread_spin_lock(&spinlock);
	
	printf("%d Thread unlock the spin lock\n",(int *)i);
	rc = pthread_spin_unlock(&spinlock);
	
	printf("%d thread complete\n",(int *)i);
	return NULL;
}

int main()
{
	int        rc=0;
	pthread_t  thread,thread1;
	
	if(pthread_spin_init(&spinlock,PTHREAD_PROCESS_PRIVATE)!=0);
		perror("init");
	printf("main, get spin lock\n");
	rc = pthread_spin_lock(&spinlock);
	
	printf("main, create the spin lock thread\n");
	rc = pthread_create(&thread,NULL, spinlockThread,(int *)1);
	
	printf("main, wait a bit holding the spin lock\n");
	sleep(10);
	
	printf("main, now unlock the spin lock\n");
	rc=pthread_spin_unlock(&spinlock);
	if(rc==0)
		printf("\n Main Thread Successfully unlocked\n");
	else
		printf("\n Main Thread Unsuccessfully unlocked\n");
		
	printf("main, wait for the thread to end\n");
	rc=pthread_join(thread,NULL);
	
	printf("Main complete\n");
	return 0;
}
