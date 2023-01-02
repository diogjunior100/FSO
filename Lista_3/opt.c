#include <stdio.h>
#include <stdlib.h>


int predictPage(int *pg, int *vetor, int qtd_paginas, int index, int qtd_quadros)
{
	
	int pos = -1;
    int aux = index;

	for (int i = 0; i < qtd_quadros; i++) 
    {
		int j;

		for (j = index; j < qtd_paginas; j++) 
        {
			if (vetor[i] == pg[j]) 
            {
				if (j > aux) 
                {
					aux = j;
					pos = i;
				}
				break;
			}
		}

		if (j == qtd_paginas)
        {
			return i;
        }
	}

    if (pos == -1)
    {
        return 0;
    }
    else{
        return pos;
    }
    
}

int procura(int valor, int *quadros, int qtd_quadros){
    for (int i = 0; i < qtd_quadros; i++)
    {
        if (quadros[i] == valor)
        {
            return 1;
        }   
    }

    return 0;
    
}

void opm(int *pg, int qtd_paginas, int qtd_quadros)
{

	int *quadros = (int *)malloc(qtd_quadros *sizeof(int));

    for (int i = 0; i < qtd_quadros; ++i)
    {
        quadros[i] = -1;
    }
    

	int count = 0;
    int index = 0;

	for (int i = 0; i < qtd_paginas; i++) 
    {
		
        if (procura(pg[i], quadros, qtd_quadros))
        {
            count++;
            continue;
        }
        

        if (index < qtd_quadros)
        {
            quadros[index++] = pg[i];
        }
        
        else{
            int j = predictPage(pg, quadros, qtd_paginas, i + 1, qtd_quadros);
		    quadros[j] = pg[i];
        }
		
	}
	
    printf("%d\n", (qtd_paginas - count));
}

int main()
{
	
    int qtd_quadros, qtd_paginas; 
    int *quadros, *paginas; 
    
    scanf("%d", &qtd_quadros);
    scanf("%d", &qtd_paginas);

    paginas = malloc(qtd_paginas * sizeof(int));
 
    for (int i = 0; i < qtd_paginas; ++i)
    {
      scanf("%d", &paginas[i]);
    }

	opm(paginas, qtd_paginas, qtd_quadros);

	return 0;
}