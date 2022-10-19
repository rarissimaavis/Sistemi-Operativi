#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

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

int main()
{
    int value;
    
    value = fork();

    if (value < 0)
    {
        printf("Errore nella system call fork\n");
    }
    
    if (value == 0)
    {
        printf("Nel processo FIGLIO\n");
        printf("Primi 10 numeri di Fibonacci: ");
        for (int i = 0; i < 10; i++)
        {
            printf("%d ", fibonacci(i));
        }
        printf("\n");
    }
    else
    {
        printf("Nel processo PADRE\n");
        printf("Primi 10 numeri Fattoriali: ");
        for (int i = 0; i < 10; i++)
        {
            printf("%d ", fattoriale(i));
        }
        printf("\n");
    }
}