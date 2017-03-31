#include <pthread.h>
#include <stdio.h>

void * print_message(void * arg) 
{
	unsigned long id = pthread_self();
	printf("Nova thread criada. TID = %lu\n",id);
	pthread_exit(0);
}

int main()
{
	pthread_t thread;

	pthread_create(&thread, NULL, print_message, NULL);
	pthread_join(thread, NULL);

	pthread_exit(0);
}