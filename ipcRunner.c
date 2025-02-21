#include <stdio.h>
#include <unistd.h>

int main(){
  pid_t hijo = fork();
  
  if (hijo == 0) {
      execl("./ipc", "ipc", "5", "A", NULL);
      
      return 1;
  } else {
      // Proceso padre
      execl("./ipc", "ipc", "3", "B", NULL);
      
      return 1;
  }
} 
