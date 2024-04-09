#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5
#define M 7

int main(){

    int i, j, k=0;
    int mt[N][M];
    int *pMT= &mt[0][0];
    srand(time(NULL));

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++, pMT++) {
            *pMT = 1 + rand() % 100;
            printf("Valor [%d][%d]: %d\n", i, j, *pMT);
        }
    }

    return 0;
}