//2311
/*
Scrivere un programma C che implementi la seguente situazione:
un processo P scrive i primi 30 numeri di Fibonacci e poi termina
In presenza di un CTRL-C immesso da tastiera P dovrà chiedere all'utente se deve continuare 
la sua esecuzione o terminare (e regolarsi di conseguenza)
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

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

    printf("\n\n%s%d\n\n%s", "Ricevuto segnale di interruzione!, segnale = ", sig, "Vuoi continuare (c) o uscire (q))? ");
    scanf("%s", answer);

    if (*answer == 'c')
    {
        signal(SIGINT, cntrl_c_handler);
    }
    else
    {
        printf("Processo terminato dall'utente\n\n");
        exit(1);
    }
}

int main()
{
    printf("Il segnale SIGINT equivale a %d\n\n", SIGINT);

    if (signal(SIGINT, cntrl_c_handler) == SIG_ERR)
    {
        printf("Errore di sistema: sigint\n");
        exit(1);
    }
    for (int i = 0; i < 30; i++)
    {
        printf("%d\n", fibonacci(i));
        sleep(1);
    }
}