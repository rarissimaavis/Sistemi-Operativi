//19/10/22
/*
Un processo P crea due figli ed aspetta la terminazione di entrambi
Il primo figlio stampa sullo schermo un messaggio indicando il proprio pid e il pid di P, poi termina
Il secondo figlio stampa sullo schermo la somma del proprio pid + il pid del padre e poi termina
Dopo la terminazione dei due figli P stampa sullo schermo un messaggio indicando il pid dei 
due figli ed il fatto che sono terminati e poi termina
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int pid1, pid2, status;

    pid1 = fork();

    if (pid1 < 0)
    {
        printf("Errore della fork\n");
        exit(0);
    }
    if (pid1 == 0)
    {
        printf("pid del primo figlio: %d, pid di P: %d\n", getpid(), getppid());
        exit(0);
    }
    else
    {
        pid2 = fork();
        
        if (pid2 < 0)
        {
            printf("Errore della fork\n");
            exit(0);
        }
        if (pid2 == 0)
        {
            printf("somma pid del secondo figlio e di P: %d\n", getpid()+getppid());
            exit(0);
        }
        else
        {
            printf("Termina il figlio con pid %d\n", wait(&status));
            printf("Termina il figlio con pid %d\n", wait(&status));
            exit(0);
        }
    }
}