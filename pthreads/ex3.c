#include <pthread.h>
#include <stdio.h>

#define MAX_THREADS 4

int global_var = 0;

// In this exercise, as there is no mutex or semaphore protecting 
// the global variable, the result of the execution is non-deterministic.
void * useful_function(void * arg) 
{
	for (int i = 0; i < 100000; i++) {
		global_var++;
	}
	pthread_exit(0);
}

int main()
{
	pthread_t threads[MAX_THREADS];
	global_var = 0;
	for (int i = 0; i < MAX_THREADS; i++) {
		pthread_create(&threads[i], NULL, useful_function, NULL);
	}
	for (int i = 0; i < MAX_THREADS; i++) {
		pthread_join(threads[i], NULL);
	}
	printf("%d\n", global_var);
	pthread_exit(0);
}