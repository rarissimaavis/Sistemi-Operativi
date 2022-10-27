//12/10/22
#include <unistd.h>
#include <stdio.h>

int main()
{
    int value, value2;
    
    value = fork();

    if (value < 0)
    {
        printf("Errore nella system call fork\n");
        exit(0);
    }
    if (value == 0)
    {
        printf("Nel processo FIGLIO\n");
        printf("Il valore di ritorno di fork: %d\n\n", value);
    }
    else
    {
        printf("Nel processo PADRE\n");
        printf("Il valore di ritorno di fork: %d\n\n", value);
    }

    if (value > 0) //solo il padre genera un nuovo figlio
    {
        value2 = fork();

        if (value2 < 0)
        {
            printf("Errore nella system call fork\n");
            exit(0);
        }   
        if (value2 == 0)
        {
            printf("Nel secondo processo FIGLIO\n");
            printf("Il valore di ritorno di fork: %d\n\n", value2);
        }
        else
        {
            printf("Nel secondo processo PADRE\n");
            printf("Il valore di ritorno della seconda fork: %d\n\n", value2);
        }
    }
}