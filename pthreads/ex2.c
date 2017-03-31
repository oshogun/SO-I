#include <pthread.h>
#include <stdio.h>

#define MAX_THREADS 4

void * print_message(void * arg) 
{
	unsigned long id = pthread_self();
	printf("Nova thread criada. TID = %lu\n",id);
	pthread_exit(0);
}

int main()
{
	pthread_t threads[MAX_THREADS];

	for (int i = 0; i < MAX_THREADS; i++) {
		pthread_create(&threads[i], NULL, print_message, NULL);
	}
	for (int i = 0; i < MAX_THREADS; i++) {
		pthread_join(threads[i], NULL);
	}

	pthread_exit(0);
}