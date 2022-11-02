//26/10/22
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("\n \n \n");
    printf("Sopra la panca\n");
    execl("/bin/echo", "echo", "la", "capra", "campa", NULL); //primo argomento sempre il nome del programma
    printf("Prova \n"); //non viene preso in considerazione perchè il processo termina quando termina echo
}