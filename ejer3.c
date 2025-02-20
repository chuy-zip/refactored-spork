#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>

int main(){
  pid_t hijo;
  
  hijo = fork();
  
  clock_t inicio, final;

  inicio = clock();
  
  if(hijo == 0) {
      printf("PID del hijo es: %d", getpid());
      
      for(int i = 0; i < 3000000; i++){
        printf("hijo dice: %d \n", i);
      }
      
      final = clock(); 
      
      double hijo_tiempo_final = (double) (final - inicio) / CLOCKS_PER_SEC;
      
      printf("Tiempo final hijo: %f \n", hijo_tiempo_final);
      
  } else {
      
      while(true){}
  }
  
  return 0;
}
