#include <stdio.h>
#include <stdlib.h> 

int acharLRU(int time[], int n)
{
   int i, minimum = time[0], pos = 0;
 
   for (i = 1; i < n; ++i)
   {
      if (time[i] < minimum)
      {
         minimum = time[i];
         pos = i;
      }
   }
 
   return pos;
}
 

int main()
{
   int qtd_quadros, qtd_paginas; 
   int *quadros, *paginas, counter = 0, time[10000]; 
   int flag1, flag2, i, j, pos, pf = 0;

   scanf("%d", &qtd_quadros);
   scanf("%d", &qtd_paginas);

   paginas = malloc(qtd_paginas * sizeof(int));
 
   for (i = 0; i < qtd_paginas; ++i)
   {
      scanf("%d", &paginas[i]);
   }
 
   quadros = (int *)malloc(qtd_quadros * sizeof(int));
   for (i = 0; i < qtd_quadros; ++i)
   {
      quadros[i] = -1;
   }
 
   for (i = 0; i < qtd_paginas; ++i)
   {
      flag1 = 0;
      flag2 = 0;
 
      for (j = 0; j < qtd_quadros; ++j)
      {
         if (quadros[j] == paginas[i])
         {
            counter++;
            time[j] = counter;
            flag1 = flag2 = 1;
            break;
         }
      }
 
      if (flag1 == 0)
      {
         for (j = 0; j < qtd_quadros; ++j)
         {
            if (quadros[j] == -1)
            {
               counter++;
               pf++;
               quadros[j] = paginas[i];
               time[j] = counter;
               flag2 = 1;
               break;
            }
         }
      }
 
      if (flag2 == 0)
      {
         pos = acharLRU(time, qtd_quadros);
         counter++;
         pf++;
         quadros[pos] = paginas[i];
         time[pos] = counter;
      }
   }
 
   printf("%d\n", pf);
 
   return 0;
}