#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    
    pid_t hijo, nieto, bisnieto;
    clock_t inicio, fin;
    inicio = clock();

    hijo = fork();

    if (hijo == 0) {
  
        nieto = fork();

        if (nieto == 0) {
            // nieto
            bisnieto = fork();

            if (bisnieto == 0) {
                // bisnieto
                for (int i = 0; i < 1000000; i++) {
                }
                
            } else {
                // nieto
                for (int i = 0; i < 1000000; i++) {
                }
                wait(NULL); // Esperar bisnieto
            }
        } else {
            // hijo
            for (int i = 0; i < 1000000; i++) {
            }
            wait(NULL); // Esperar nieto
        }
    } else {
        // padre
        wait(NULL); // Esperar hijo
        fin = clock();
        double finalisimo = (double)(fin - inicio);
        
        printf("Tiempo: %f\n", finalisimo);
    }

    return 0;
}
