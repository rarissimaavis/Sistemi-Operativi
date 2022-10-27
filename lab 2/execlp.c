//26/10/22
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("\n \n \n");
    printf("Sopra la panca\n");
    execlp("echo", "echo", "la", "capra", "campa", NULL); //path contiene /bin per default
    printf("Prova \n"); //non viene preso in considerazione perchè il processo termina quando termina echo
}