#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

int sharedVar = 5; //shared variable protected variable
pthread_mutex_t my_mutex;

void *thread_inc(void *arg)
{
	pthread_mutex_lock(&my_mutex);
	sharedVar++;

	printf("after increament %d\n", sharedVar);
	pthread_mutex_unlock(&my_mutex);
}

void *thread_dec(void *arg)
{
	pthread_mutex_lock(&my_mutex);
	sharedVar--;

	printf("after decrement %d\n", sharedVar);
	pthread_mutex_unlock(&my_mutex);
}

int main()
{
	pthread_t t1,t2;

	pthread_mutex_init(&my_mutex,NULL);

	pthread_create(&t1,NULL,thread_inc,NULL);
	pthread_create(&t2,NULL,thread_dec,NULL);

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);

	printf("shared variable %d\n", sharedVar);

	return 0;
}
