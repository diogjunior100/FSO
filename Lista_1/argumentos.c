#include <stdio.h>

int main(int argc, char *argv[])
{
    int referencia = argc - 1;
    if(referencia < 0){
        return 0;
    }
    
    printf("%d\n", argc-1);

    for (int i = 1; i <= referencia; i++)
    {
        printf("%s ", argv[i]);
        printf("\n");
    }
    
    return 0;
}
