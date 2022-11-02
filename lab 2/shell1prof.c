//02/11/22
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
    char buf[512];
    int pid, status;

    printf("%%"); //prompt

    while (fgets(buf, 512, stdin) != NULL)
    {
        buf[strlen(buf)-1] = 0; //sostituisce newline con NULL
        if ((pid = fork()) < 0)
        {
            printf("errore di sistema: fork\n");
            exit(1);
        }
        else if (pid == 0) //processo figlio 
        {
            if (execlp(buf, buf, (char *) 0) == -1)
            {
                printf("errore: non posso eseguire %s\n", buf);
                exit(1);
            }
        }
        if ((pid = waitpid(pid, &status, 0)) < 0) //padre
        {
            printf("errore di sistema: waitpid\n");
            exit(1);
        }
        printf("%%");
    }
    exit(0);
}