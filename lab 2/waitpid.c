/*
Un processo P crea due figli e aspetta la terminazione di entrambi
Il primo figlio stamperà sullo schermo un messaggio indicando il proprio pid e poi stampa sullo schermo i numeri da 1 a 50
Il secondo figlio stampa sullo schermo il pid del padre e poi stampa sullo schermo i numeri da 101 a 150 e poi termina
Dopo la terminazione dei due figli P stampa sullo schermo un messaggio indicando il pid dei due figli ed il fatto che sono terminati e poi termina
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int pid1, pid2;

    pid1 = fork();

    if (pid1 < 0)
    {
        printf("Errore della fork\n");
        exit(0);
    }
    if (pid1 == 0)
    {
        printf("pid del primo figlio: %d\n", getpid());
        for (int i = 1; i <= 50; i++)
        {
            printf("%d ", i);
        }
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
            printf("\npid di P: %d\n", getppid());
            for (int i = 101; i <= 150; i++)
            {
                printf("%d ", i);
            }
            exit(0);
        }
        else
        {
            printf("\nTermina il figlio con pid %d\n", waitpid(-1, NULL, 0));
            printf("\nTermina il figlio con pid %d\n", waitpid(-1, NULL, 0));
            exit(0);
        }
    }
}