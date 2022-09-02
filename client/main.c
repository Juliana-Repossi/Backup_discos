#include <time.h>
#include "../include/worstfit.h"
#include "../include/bestfit.h"

int main(int argc, char **argv) 
{
  //receber arquivo por linha de comando
  if(argc!=2)
  {
    printf("Número de argumentos inválidos passados por parâmentro\n");
    exit(1);
  }

  //struct timespec beginCPU, endCPU; 
  //double seconds, nanoseconds, elapsed;

  // Começa a medir o tempo
  //clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &beginCPU);

  // técnica de worstfit 
  printf("%d\n",Worstfit(argv[1]));
  
  //técnica de bestfit 
  printf("%d\n",Bestfit(argv[1]));

  //técnica de worstfit decrescente 
  printf("%d\n",Worstfit_decrescente(argv[1]));
  
  //técnica de bestfit decrescente->
  printf("%d\n",Bestfit_decrescente(argv[1]));  
  
  // Termina de medir o tempo
  //clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &endCPU);

  
  // calcula o tempo de CPU
  //seconds = endCPU.tv_sec - beginCPU.tv_sec;
  //nanoseconds = endCPU.tv_nsec - beginCPU.tv_nsec;
  //elapsed = seconds + nanoseconds*1e-9;

  //printf("tempo total:  %.2f\n",elapsed);

  return 0;  
}
