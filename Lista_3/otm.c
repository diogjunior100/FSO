#include <stdio.h>
#include <stdlib.h>

int main()
{
    int qtd_paginas, paginas, *vetor, temp[10000];
    int qtd_quadros, *quadro;
    int flag1, flag2, flag3; 
    int i, j, k, pos, max, pf = 0;

    
    scanf("%d", &qtd_quadros);
    scanf("%d", &qtd_paginas);
    
    vetor = malloc(qtd_paginas * sizeof(int));
    
    for(i = 0; i < qtd_paginas; i++){
        scanf("%d", &vetor[i]);
    }
    
    quadro = (int *)malloc(qtd_quadros *sizeof(int));
    for(i = 0; i < qtd_quadros; i++){
        quadro[i] = -1;
    }
    
    for(i = 0; i < qtd_paginas; ++i){
        flag1 = flag2 = 0;
        
        for(j = 0; j < qtd_quadros; ++j)
        {
            if(quadro[j] == vetor[i])
            {
                   flag1 = flag2 = 1;
                   break;
            }
        }
        
        if(flag1 == 0)
        {
            for(j = 0; j < qtd_quadros; ++j)
            {
                if(quadro[j] == -1)
                {
                    pf++;
                    quadro[j] = vetor[i];
                    flag2 = 1;
                    break;
                }
            }    
        }
        
        if(flag2 == 0)
        {
            flag3 = 0;
        
        for(j = 0; j < qtd_quadros; ++j)
        {
            temp[j] = -1;
            
            for(k = i + 1; k < qtd_paginas; ++k)
            {
                if(quadro[j] == vetor[k])
                {
                    temp[j] = k;
                    break;
                }
            }
        }
            
        for(j = 0; j < qtd_quadros; ++j)
        {
            if(temp[j] == -1){
                pos = j;
                flag3 = 1;
                break;
            }
        }
            
        if(flag3 ==0){
                max = temp[0];
                pos = 0;
            
            for(j = 1; j < qtd_quadros; ++j){
                if(temp[j] > max){
                    max = temp[j];
                    pos = j;
                }
            }               
        }

        pf++;
        }
    }
    

    printf("%d\n", pf);
    
    return 0;
}