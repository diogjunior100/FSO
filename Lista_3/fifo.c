#include <stdio.h>
#include <stdlib.h>

int main()
{
    int qtd_paginas, paginas;
    int *vetor;
    int qtd_quadros, *quadro;
    int j = 0, pf = 0, antigo = 0, i = 0;
    

    scanf("%d", &qtd_quadros);
    scanf("%d", &qtd_paginas);

    vetor = malloc(qtd_paginas * sizeof(int));

    for (i = 0; i < qtd_paginas; i++)
    {
        scanf("%d", &paginas);
        vetor[i] = paginas;
    }


    quadro = (int *)malloc(qtd_quadros * sizeof(int));

    for (i = 0; i < qtd_quadros; i++)
    {
        quadro[i] = -1;
    }

    j = 0;
    pf = 0;
    antigo = 0;

    for (i = 0; i < qtd_paginas; i++)
    {
        for (j = 0; j < qtd_quadros; j++)
        {
            if (vetor[i] == quadro[j])
            {
                break;
            }

            if (j == qtd_quadros - 1 && vetor[i] != quadro[j])
            {
                pf++;
                //printf("teste - %d\n", pf);
                quadro[antigo] = vetor[i];
                if (antigo == (qtd_quadros - 1))
                {
                    antigo = 0;
                }
                else
                {
                    antigo++;
                }
            }
        }
    }

    printf("%d\n", pf);
    


    return 0;
}