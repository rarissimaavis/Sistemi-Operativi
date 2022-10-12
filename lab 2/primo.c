#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t value;

    value = fork();

    if (value < 0) //errore
    {
        printf("Errore nella system call fork\n");
    }
    else
    {
        printf("In main value == %d\n", value);
    }
}