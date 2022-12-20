#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


#define less(A,B) ((A) < (B))
#define exch(A,B) {int t; t=A, A=B, B=t;}
#define cmpexch(A,B) {if (less(B,A)) exch(A,B);}

int tam;

int separa(int *v, int l, int r){
    int pivo = v[r];
    int aux, j = l;

    for (int a = l; a < r; a++)
    {
        if (v[a] <= pivo)
        {
           aux = v[j];
           v[j] = v[a];
           v[a] = aux; 

           ++j;
        }
        
    }

    aux = v[j];
    v[j] = v[r];
    v[r] = aux;
    
    return j;
}

void quickSort(int *v, int l, int r){

    if (r<=l){
        return;
    }
    
    cmpexch(v[(l + r)/2], v[r]);
    cmpexch(v[l], v[(l + r)/2]);
    cmpexch(v[r], v[(l + r)/2]);

    
    int j = separa(v,l,r);
    quickSort(v, l, j-1);
    quickSort(v, j+1, r);

    

}


void *ordenaqs(void *args){
    quickSort((int *)args, 0, tam - 1);
    return;
}


int main()
{
    int *vetor1, *vetor2;
    int saida, valor = 0; 
    pthread_t p1, p2;
    
    scanf(" %d", &tam);

    vetor1 = malloc(sizeof(int)*tam);
    vetor2 = malloc(sizeof(int)*tam);

    for (int i = 0; i < tam; i++){
        scanf(" %d", &vetor1[i]);
    }

    for (int j = 0; j < tam; j++){
        scanf(" %d", &vetor2[j]);
    }
    
    saida = pthread_create(&p1, NULL, ordenaqs, (void *)vetor1);
    saida = pthread_create(&p2, NULL, ordenaqs, (void *)vetor2);

    pthread_join(p1, NULL);
    pthread_join(p2, NULL);

    for (int i = 0; i < tam; i++){
        if (vetor1[i] != vetor2[i]){
            valor = 1;
            break;
        }
        
    }

    if (valor == 0){
        printf("Mesmos elementos\n");
    }
    else{
        printf("Diferentes\n");
    }
    
        
    return 0;
}
