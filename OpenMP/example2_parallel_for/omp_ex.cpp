#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Main routine
int main (int argc, char *argv[]){
  int i, n=20;
  double itime, ftime;
  omp_set_num_threads(10);
	
  #pragma omp parallel shared(n) private(i)
  {
    itime = omp_get_wtime();

	  #pragma omp for
	  for(i=0; i<n; i++)
		  printf("Thread %d executes loop iteration %d\n", omp_get_thread_num(),i);
  
    //#pragma omp single{}
    ftime = omp_get_wtime();
    printf("Time: %f, thread: %d\n", ftime - itime, omp_get_thread_num());
    
  }
    printf("End by thread:%d", omp_get_thread_num());
	return 0;
}