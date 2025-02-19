#include <stdio.h>
#include <time.h>

int main() {

    clock_t inicio, final;

    inicio = clock();

    for (int i = 0; i < 1000000; i++) {
        
    }
    for (int i = 0; i < 1000000; i++) {

    }
    for (int i = 0; i < 1000000; i++) {

    }

    final = clock();

    double finalisimo = (double)(final - inicio);

    printf("Tiempo final: %f \n", finalisimo);

    return 0;
}
