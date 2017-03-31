#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
	int i;
	int proc = fork();
	if (proc > 0)
		printf("Processo pai %d criou %d\n", getpid(), proc);
	else
		printf("Processo filho %d\n",getpid());
	for (i = 0; i < 3; i++) {
		if (proc > 0) {
			proc = fork();
			if (proc > 0)
				printf("Processo pai %d criou %d\n\n", getpid(), proc);	
		} else {
			printf("Processo filho %d\n",getpid());
			break;
		}
	}

}