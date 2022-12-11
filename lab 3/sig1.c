//2311
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

//eseguire in background: gcc sig.c | ./a.out & | kill -s 10 (12) pid (che esce da ./a.out &)

void sig_usr(int signo)
{
    if (signo == SIGUSR1)
    {
        printf("ricevuto SIGUSR1\n\n");
    }
    else if (signo == SIGUSR2)
    {
        printf("Ricevuto SIGUSR2\n\n");
    }
}

int main()
{
    if (signal(SIGUSR1, sig_usr) == SIG_ERR)
    {
        printf("errore di sistema: sigusr1\n");
        exit(1);
    }
    if (signal(SIGUSR2, sig_usr) == SIG_ERR)
    {
        printf("errore di sistema: sigusr2\n");
        exit(1);
    }
    while (-1) pause();
}