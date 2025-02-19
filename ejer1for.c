#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Proceso padre: %d)\n", getpid());

    for (int i = 0; i < 4; i++) {
        fork(); 
    }
    
    printf("proceso despus del for: %d \n", getpid());
    return 0;
}
