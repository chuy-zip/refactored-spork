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
      printf("error al crear la memoria compartida\n");
      return 1;
    }
    
    // configurar tamanio memoria
    int truncate = ftruncate(shm_file_descriptor, SHM_SIZE);
    
    if (truncate == -1) {
      printf("Error al configurar tamanio memroria\n");
      return 1;
    }
    
    // aqui hay muchos parametros
    // el 0 es que el sistema elige la dir de memoria
    // PROT READ  | WRITE son permisos
    // MAP_SHARED indica memoria compartida entre procesos
    // el otro 0 es offset dentro de la memoria 
    
    char* ptr = mmap(0, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_file_descriptor, 0);
    if (ptr == MAP_FAILED) {
        printf("Error al mapear memoria \n");
        return 1;
    }
    
    // ahora los pipes
    int pipefd[2];
    int pipes = pipe(pipefd);
    if (pipes == -1) {
        printf("no se pudo crear un pipe \n");
        return 1;
    }

    // Crear un proceso hijo
    pid_t pid = fork();
    if (pid < 0) {
        printf("no se creo el hijo \n");
        return 1;
    } 
    
    if (pid == 0) {
        printf("hijo creado, tiene PID %d, y el padre es %d \n", getpid(), getppid());    
    } else {
      printf("soy el padre con pid: %d \n", getpid());
    }

    
    return 0;
}
