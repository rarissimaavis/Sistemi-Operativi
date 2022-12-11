# Sistemi-Operativi
## lab 2: process control
- identificatori di processi: getpid e getppid
- creazione di nuovi processi: fork
- fattoriale e fibonacci: un processo crea un figlio, il figlio scrive sullo schermo i primi 10 numeri di Fibonacci mentre il padre i primi 10 numeri Fattoriali
- chiedere informazioni sullo stato di uscita del figlio: wait e waitpid
- eseguire un programma diverso dal padre: exec
- shell: simulare una shell utilizzando le system call
- terminazione: exit

## lab 3: signals
- sigusr1, sigusr2
- sigint (ctrl-c)
- ignorare il segnale: sig_ign 
- mandare un segnale ad un processo specificato da pid: kill
- mandare un segnale a se stesso: raise

## intercorso
- intercorso1: fork, waitpid, exec