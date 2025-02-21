#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
  pid_t hijo = fork();
  
  if (hijo < 0) {
        perror("fork");
        return 1;
  }
  if (hijo == 0) {
      execl("./ipc", "ipc", "5", "A", NULL);
      perror("execl");  // Si execl falla
      return 1;
  } else {
      // Proceso padre
      // en el doc puse que 1000 deberia ser suficiente, pero es importante recordar que 
      // que el tiempo del fork puede variar. Pero al correr varias veces el programa
      // se alcanza a ver que con 1000 microsegundos casi siempre se puede ver el caso en
      // el que la memoria compartida ya se ha creado
      execl("./ipc", "ipc", "3", "B", NULL);
      usleep(1000);
      wait(NULL);
      perror("execl");  // Si execl falla
      return 1;
  }
  return 0;
} 
