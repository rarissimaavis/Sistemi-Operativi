//30/11
/*
Scrivere un programma C che implementi la seguente situazione:
Un processo P crea un figlio ed aspetta che il figlio termini
I due figli saranno in esecuzione concorrente
Il figlio F scriverà i primi 45 numeri di Fibonacci ed in presenza di un CTRL-C immesso da tastiera dovrà 
creare a sua volta un figlio F1 che chiederà all'utente se l'esecuzione di F deve continuare o se F deve terminare 
(e dovrà quindi regolarsi di conseguenza eventualmente uccidendo F e comunque terminando)
Dopo la terminazione del figlio il padre P stampa sullo schermo un messaggio indicando il pid del figlio 
ed il fatto che è terminato e poi a sua volta termina
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

int fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

void cntrl_c_handler(int sig)
{
    char answer[512];
    int pidf;

    signal(SIGINT, SIG_IGN);

    pidf = fork();

    if (pidf == 0)
    {
        printf("\n\n%s%d\n\n%s", "Ricevuto segnale di interruzione!, segnale = ", sig, "Vuoi continuare (c) o uscire (q)? ");
        scanf("%s", answer);
        if (*answer == 'c') 
        {
            exit(0);
        }
        else
        {
            kill(getppid(), SIGKILL);
            raise(SIGKILL);
        }
    }
    else
    {
        wait(NULL);
        signal(SIGINT, cntrl_c_handler);
    }
}

int main()
{
    int pid;

    pid = fork();

    if (pid == 0)
    {
        signal(SIGINT, cntrl_c_handler);
        for (int i = 0; i < 46; i++)
        {
            sleep(1);
            printf("%d\n", fibonacci(i));
        }
    }
    else
    {
        signal(SIGINT, SIG_IGN);
        wait(NULL);
        printf("Padre: figlio terminato. Il suo pid: %d\n", pid);
    }
}