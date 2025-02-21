#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

    int n = atoi(argv[1]);  
    char x = argv[2][0]; 

    printf("Número n: %d\n", n);
    printf("Letra x: %c\n", x);

    return 0;
}
