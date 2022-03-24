#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/mman.h>

void *Proc(void *param)
{
	sleep(2);
	return 0;
}

int main()
{
	pthread_attr_t Attr;
	pthread_t id;
	void *stk;
	size_t size;
	int err;

	size_t my_stksize = 0x3000000;
	void *my_stack;

	pthread_attr_init(&Attr);

	pthread_attr_getstacksize(&Attr,&size);
	pthread_attr_getstackaddr(&Attr,&stk);

	printf("Default: Addr=%08x default Size: %d\n",stk,size);

	my_stack=(void*)malloc(my_stksize);

	//printf("Default: Addr=%08x default Size: %d\n",my_stack,my_stksize);

	pthread_attr_setstack(&Attr,my_stack,my_stksize);

	pthread_create(&id,&Attr,Proc,NULL);

	pthread_attr_getstack(&Attr,&stk,&size);

	printf("new: Addr=%08x new Size: %d\n",stk,size);

	sleep(3);

}
