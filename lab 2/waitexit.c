//2311
//slide 28
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int pid, status;

    pid = fork();

    if (pid == 0)
    {
        printf("figlio: sto per terminare\n");
        exit(0);
    }
    else
    {
        pid = wait(&status);
        printf("Termina il figlio con pid %d\n", pid);
        if ((char) status == 0)
        {
            printf("Terminazione volontaria con stato %d\n", status>>8);
        }
        else
        {
            printf("Terminazione involontaria per segnale %d\n", (char) status);
        }
    }
}