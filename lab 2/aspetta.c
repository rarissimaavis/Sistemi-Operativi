//19/10/22
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int pid1, pid2, pid3, status;
    //il padre crea tre figli e li aspetta andando a dire in che ordine terminano

    pid1 = fork(); 
    
    if (pid1 == 0)
    {
        sleep(4);
    }
    else
    {
        pid2 = fork();
        if (pid2 == 0)
        {
            sleep(1);
        }
        else
        {
            pid3 = fork();
            if (pid3 == 0)
            {
                sleep(2);
            }
            else
            {
                printf("Termina il figlio con pid %d\n", wait(NULL));
                printf("Termina il figlio con pid %d\n", wait(&status));
                printf("Termina il figlio con pid %d\n", wait(&status));
            }
        }
    }
}
