#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>       //open, O_CREAT, O_RDWR, etc.
#include <sys/mman.h>    //lo relcionado a memoria compartida mmap, shm_open, shm_unlink
#include <sys/stat.h>    // modos de permisos (S_IRUSR, S_IWUSR, etc.)
#include <unistd.h>      //ftruncate, close
#include <errno.h>       // el nombre creo que lo explica pero igal, es errno

#define SHM_SIZE 1024  // memoria compartida como global constante

// por la complejidad del ejercicio y poeque hay varias cosas nuevas, esta vez
//si colocare mas comentarios :)

int main(int argc, char** argv) {

    if(argc != 3) {
      printf("Uso correto (solo 3 argumentos) : ./ipc <n> <x> \n");
      printf("Donde 'n' es numero entero y 'x' una letra \n");
      return 1;
    }
    
    int n = atoi(argv[1]);  
    char x = argv[2][0]; 

    printf("Numero n: %d\n", n);
    printf("Letra x: %c\n", x);
    
    // nombre memoria compartida
    const char* shm_name = "/mem_compartida";
    
    int shm_file_descriptor = shm_open(shm_name, O_CREAT | O_RDWR, 0666);
    // O_CREAT es un "crear si no existe"
    // O_RDWR abre para leer y escribir RD read WR write
    // 0666 permiso de escritura para todo usuario
    
    if(shm_file_descriptor == -1) {
      printf("error al crear la memoria compartida");
      return 1;
    }
    
    return 0;
}
