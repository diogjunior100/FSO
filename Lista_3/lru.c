#include<stdio.h>
    
int main()
{
    int i = 0, j = 0, pos, k, l;
    int a = 0, b = 0, pf = 0;
    int qtd_quadros, quadros[10000];
    int temp[10000];
    int qtd_paginas, paginas[10000];


    scanf("%d", &qtd_quadros);
    scanf("%d", &qtd_paginas);

    for(i = 0; i < qtd_paginas; ++i){
        scanf("%d", &paginas[i]);
    }

    for(i = 0; i < qtd_quadros; ++i){
            quadros[i] = -1;
    }
    
    for(j = 0; j < qtd_paginas; j++)
    {
            a = 0, b = 0;

            for(i = 0; i < qtd_quadros; i++)
            {
                if(quadros[i] == paginas[j])
                {
                        a = 1;
                        b = 1;
                        break;
                }
            }

            if(a == 0)
            {
                for(i = 0; i < qtd_quadros; i++)
                {
                    if(quadros[i] == -1)
                    {
                        quadros[i] = paginas[j];
                        b = 1;
                        pf++;
                        break;
                    }
                }
            }

            if(b == 0)
            {
                for(i = 0; i < qtd_quadros; i++)
                {
                    temp[i] = 0;
                }

                for(k = j - 1, l = 1; l <= qtd_quadros - 1; l++, k--)
                {
                    for(i = 0; i < qtd_quadros; i++)
                    {
                        if(quadros[i] == paginas[k])
                        {
                            temp[i] = 1;
                        }
                    }
                }

                for(i = 0; i < qtd_quadros; i++)
                {
                    if(temp[i] == 0)
                        pos = i;
                }

                quadros[pos] = paginas[j];
                pf++;
            }
    }

    printf("%d\n", pf);
    
    return 0;
}