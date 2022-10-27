//12/10/22
#include <unistd.h>
#include <stdio.h>

int main()
{
    int value;
    
    value = fork();

    if (value < 0)
    {
        printf("Errore nella system call fork\n");
        exit(0);
    }
    //dobbiamo sempre distinguere esplicitamente quello che fa il padre da quello che fa il figlio
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
}