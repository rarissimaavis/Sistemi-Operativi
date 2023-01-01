#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int fib(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return fib(n-1) + fib(n-2);
}

int fatt(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n*fatt(n-1);
}

void cntrl_c_handler1(int sign)
{
    printf("\n\n%s%d\n\n", "Segnale ricevuto! il segnale è: ", sign);
    printf("il decimo numero di Fibonacci è: %d\n", fib(10));
}

void cntrl_c_handler2(int sign)
{
    char answer[512];

    printf("\n\n%s%d\n\n%s", "Segnale ricevuto! il segnale è: ", sign, "Vuoi continuare (c) o terminare (q)? ");
    scanf("%s", answer);
    if (*answer == 'c')
    {
        printf("figlio 2, continuo\n");
    }
    else
    {
        printf("figlio 2, processo terminato dall'utente\n");
        exit(0);
    }
}

int main()
{
    int value, value2;
    value = fork(); //creazione del primo figlio
    if (value < 0)
    {
        printf("Errore nella fork 1\n");
        exit(0);
    }
    if (value == 0) //nel primo figlio
    {
        if (signal(SIGINT, cntrl_c_handler1) == SIG_ERR)
        {
            printf("Errore nella signal 1\n");
            exit(0);
        }
        for (int i = 0; i < 10; i++)
        {
            printf("%d\n", fib(i));
            sleep(1);
        }
        exit(0);
    }
    else //padre
    {
        value2 = fork(); //creazione del secondo figlio
        if (value2 < 0)
        {
            printf("Errore nella fork 2\n");
            exit(0);
        }
        if (value2 == 0) //nel secondo figlio
        {
            if (signal(SIGINT, cntrl_c_handler2) == SIG_ERR)
            {
                printf("Errore nella signal 2\n");
                exit(0);
            }
            for (int j = 0; j < 10; j++)
            {
                printf("%d\n", fatt(j));
                sleep(1);
            }
            exit(0);
        }
        else //padre
        {
            if (signal(SIGINT, SIG_IGN) == SIG_ERR)
            {
                printf("Errore nella signal 3\n");
                exit(0);
            }
            printf("Padre, somma pid figli: %d\n", wait(NULL)+wait(NULL));
            printf("I figli sono terminati\n");
            exit(0);
        }
    }
}