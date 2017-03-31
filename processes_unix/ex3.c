#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
	// Prepare to blow your mind
	printf("Processo raiz %d\n", getpid());
	int id = fork(); // filho de numero 1
	if (id > 0) {
		printf ("Processo nutella %d filho de %d\n", id, getpid());
		id = fork(); // filho de numero 2
		if (id > 0) {
			printf ("Dad: %d Filho: %d\n", getpid(), id);
		} else {
			// filho 2 vai parir aqui
			id = fork();
			if (id > 0) {
				printf ("Fatherzão: %d Fio: %d\n",getpid(), id);
				id = fork(); {
					if (id > 0) {
						printf ("Pai: %d, Filho %d\n",getpid(), id);
					}
				}
			}
		} 
	} else {
		// filho 1 vai parir aqui 
		id = fork();
			if (id > 0) {
				printf ("[2]Fatherzão: %d Fio: %d\n",getpid(), id);
				id = fork(); {
					if (id > 0) {
						printf ("[2]Pai: %d, Filho %d\n",getpid(), id);
					}
				}
			}
	}
	return 0;
}