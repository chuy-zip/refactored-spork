#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Proceso padre PID %d)\n", getpid());

    fork(); 
    fork(); 
    fork(); 
    fork(); 

    printf("Proceso hijo: %d)\n", getpid());

    return 0;
}
