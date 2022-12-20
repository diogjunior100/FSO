#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int qtd;

void sinal(int sig){

    if (sig == SIGUSR1)
    {
        printf("SIGUSR1 eh para aproveitar mais um pouco\n");
    }

    if (sig == SIGALRM)
    {
        if (qtd < 2)
        {
            printf("Ai que sono, quero dormir mais um pouco\n");
            qtd++;
        }
        else{
            printf("Os incomodados que se mudem, tchau\n");
            exit(0);
        }
        
    }

}


int main()
{
    qtd = 0;
    
    signal(SIGUSR1, sinal);
    signal(SIGALRM, sinal);


    while (1)
    {
        /* code */
    }
    

    return 0;
}
