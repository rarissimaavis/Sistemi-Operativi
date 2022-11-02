//02/11/22
/*
Scrivere un programma C che, utilizzando le system call studiate simuli una piccola shell
In particolare il processo associato al programma dovrà ciclicamente:
- stampare un prompt: %
- leggere il comando inserito dall’utente dopo il prompt
- creare un nuovo figlio, che dovrà eseguire il comando utente
- aspettare la terminazione del figlio
I comandi da eseguire non avranno argomenti
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
    int pid;
    char comando[10];

    while (1)
    {
        printf("%% "); //prompt
        scanf("%s", comando);

        pid = fork();

        if (pid < 0)
        {
            printf("Errore della fork\n");
            exit(0);
        }

        if (pid == 0)
        {
            execlp(comando, comando, NULL);
        }

        wait(NULL);
    }
}

