#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Main routine
int main (int argc, char *argv[]){
  omp_set_num_threads(10); // export OMP_NUM_THREADS=4
	
  #pragma omp parallel //num_threads(3)
  {
	//if (omp_get_thread_num() == 1)
	printf("The parallel region is executed by thread %d\n", omp_get_thread_num());
  }
	return 0;
}