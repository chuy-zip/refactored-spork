#include <stdio.h>
#include <time.h>

int main() {

    clock_t inicio, final;

    inicio = clock();

    for (int i = 0; i < 1000000; i++) {
        printf("%d \n", i);
    }
    for (int i = 0; i < 1000000; i++) {
        printf("%d \n", i);
    }
    for (int i = 0; i < 1000000; i++) {
        printf("%d \n", i);
    }

    final = clock();

    double finalisimo = (double)(final - inicio) / CLOCKS_PER_SEC;

    printf("Tiempo final: %f \n", finalisimo);

    return 0;
}
