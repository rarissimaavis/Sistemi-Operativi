/*
Scrivere un programma C che implementi la seguente situazione:
Un processo P crea due figli ed aspetta la terminazione di entrambi
Il primo figlio stamperà sullo schermo un messaggio indicando il proprio pid ed i numeri da 1 a 5000, dopo di ciò terminerà
Il secondo figlio stamperà sullo schermo 5000 volte il pid del padree poi eseguirà il comando /bin/ls
Dopo la terminazione dei due figli P stamperà sullo schermo un messaggio indicando il pid dei due figli
ed il fatto che sono terminati e poi a sua volta terminerà
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int pid1, pid2, status;

    pid1 = fork(); //P crea il primo figlio

    if (pid1 < 0) //se la fork fallisce restituisce un valore negativo
    {
        printf("errore della system call fork (1)\n");
        exit(0);
    }
    if (pid1 == 0) //nel processo figlio (1)
    {
        printf("il pid del primo figlio è: %d\n", getpid());
        for (int i = 1; i <= 5000; i++)
        {
            printf("%d ", i);
        }
        exit(0);
    }
    else //nel processo padre
    {
        pid2 = fork(); //padre crea il secondo figlio

        if (pid2 < 0)
        {
            printf("errore della system call fork (2)\n");
            exit(0);
        }
        if (pid2 == 0) //nel processo figlio (2)
        {
            for (int j = 0; j < 5000; j++)
            {
                printf("pid del padre: %d\n", getppid());
            }
            execlp("ls", "ls", (char*) 0);
        }
        else //nel processo padre
        {
            printf("figlio 1 terminato, pid: %d\n", waitpid(pid1, &status, 0));
            printf("figlio 2 terminato, pid: %d\n", waitpid(pid2, &status, 0));
            exit(0);
        }
    }
}