#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20

int main(){

    int i;
    int vt[N];
    int *pVT= vt;

    srand(time(NULL));

    for ( i = 0; i < N; i++, pVT++)
    {
        *pVT=1+rand()%100;
        printf("Numero %d: %d\n", i, *pVT);
    }
    

    return 0;
}