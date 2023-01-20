#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{

    FILE *f1, *f2;
    unsigned int retorno1, retorno2; 
    int k, i,j, aux = 0;
    char *conteudo1, *conteudo2;

    conteudo1 = malloc(sizeof(char) * 400 * 1000000);
    conteudo2 = malloc(sizeof(char) * 400 * 1000000);

    for (i = 1; i < argc; i++)
    {
        f1 = fopen(argv[i], "rb");
        retorno1 = fread(conteudo1, sizeof(char), 300 * 1000000, f1);
        for (j = i + 1; j < argc; j++)
        {
            f2 = fopen(argv[j], "rb");
            retorno2 = fread(conteudo2, sizeof(char), 300 * 1000000, f2);
            printf("%s %s ", argv[i], argv[j]);

            if (retorno1 != retorno2)
            {
                printf("diferentes\n");
            }
            else
            {
                aux = 0;
                for (k = 0; k < retorno1; k++)
                {
                    if (conteudo1[k] != conteudo2[k])
                    {
                        printf("diferentes\n");
                        aux = 1;
                        break;
                    }
                }
                if (aux == 0)
                {
                    printf("iguais\n");
                }
            }
            fclose(f2);
        }
        fclose(f1);
    }

    return 0;
}