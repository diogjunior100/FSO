#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
    void *biblioteca = NULL;
    
    biblioteca = dlopen(argv[1], RTLD_NOW);
    if (biblioteca == NULL)
    {
        printf("nao disponivel\n");
        return 0;
    }

    //1
    int (*imprime)() = dlsym(biblioteca, "imprime");
    if (dlerror() != NULL)
    {
        printf("nao implementado\n");
    }
    else
    {
        printf("%d\n", imprime());
    }
    
    
    //2
    int (*calcula)(int,int) = dlsym(biblioteca, "calcula");
    if (dlerror() != NULL)
    {
        printf("nao implementado\n");
    }
    else{
        printf("%d\n", calcula(atoi(argv[2]), atoi(argv[3])));
    }
    
    
    //3
    int (*trigo)(double) = dlsym(biblioteca, "trigo");
    if (dlerror() != NULL)
    {
        printf("nao implementado\n");
    }
    else{
        printf("%d\n", trigo(atof(argv[4])));
    }
    

    dlclose(biblioteca);
          

    return 0;
}
