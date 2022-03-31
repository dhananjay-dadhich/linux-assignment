#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>



pthread_t tid1,tid2;
void *t1(void *arg){
printf("new thread created\n");
}




void *t2(void *arg){
printf("new thread created\n");
}



int main(){
int s1,s2;
printf("Main started\n");
s1 = pthread_create(&tid1,NULL,t1,NULL);
s2 = pthread_create(&tid1,NULL,t1,NULL);
printf("Main ended\n");
pthread_exit(NULL);
// printf("if this executes then there's error in code!\n");
return 0;
}
