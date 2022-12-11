//30/11
/*
Scrivere un programma C che implementi la seguente situazione:
Un processo P crea due figli ed aspetta la terminazione di entrambi 
I due figli saranno in esecuzione concorrente
Il primo figlio scriverà i primi 30 numeri di Fibonacci e poi terminerà. In presenza di un CTRL-C immesso da tastiera
dovrà scrivere a schermo il proprio pid e continuare la sua esecuzione
Il secondo figlio scriverà i primi 20 fattoriali ed in presenza di un CTRL-C immesso da tastiera dovrà chiedere 
all'utente se deve continuare la sua esecuzione o terminare (e regolarsi di conseguenza)
Dopo la terminazione dei due figli il padre P stamperà sullo schermo un messaggio indicando il pid dei due figli 
ed il fatto che sono terminati e poi terminerà
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

int fattoriale(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n*fattoriale(n-1);
}

void cntrl_c_handler1(int sig)
{
    char answer[512];

    printf("\n\n%s%d\n\n", "Segnale di interruzione!, segnale = ", sig);
    printf("1 figlio, il mio pid è: %d\n", getpid());
}

void cntrl_c_handler2(int sig)
{
    char answer[512];

    printf("\n\n%s%d\n\n%s", "Ricevuto segnale di interruzione!, segnale = ", sig, "Vuoi continure (c) o uscire (q)? ");
    scanf("%s", answer);

    if (*answer == 'c')
    {
        printf("2 figlio: continuo\n");
    }
    else 
    {
        printf("Processo terminato dall'utente\n\n");
        exit(0);
    }
}

int main()
{
    int value, value2;

    value = fork();

    if (value < 0)
    {
        printf("Errore prima fork\n");
        exit(0);
    }
    if (value == 0)
    {
        signal(SIGINT, cntrl_c_handler1);
        for (int i = 0; i < 8; i++)
        {
            sleep(1);
            printf("%d\n", fibonacci(i));
        }
        exit(0);
    }
    if (value > 0)
    {
        value2 = fork();

        if (value2 < 0)
        {
            printf("Errore seconda fork\n");
            exit(0);
        }
        if (value2 == 0) 
        {
            signal(SIGINT, cntrl_c_handler2);
            for (int i = 0; i < 20; i++)
            {
                sleep(1);
                printf("%d\n", fattoriale(i));
            }
            exit(0);
        }
        else
        {
            signal(SIGINT, SIG_IGN);
            wait(NULL);
            wait(NULL);
            printf("\n");
            printf("Padre: pid del primo figlio: %d\n", value);
            printf("Padre: pid del secondo figlio: %d\n", value2);
            printf("I figli sono terminati\n");
        }
    }
}