#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Main routine
int main (int argc, char *argv[]){
	omp_set_num_threads(4);

	int n = 40, id, np, i, sum=0;
	double a[n];
	double itime, ftime;

	itime = omp_get_wtime();

	for(i = 0; i < n; i++){ 
		a[i] = i;
	}

    #pragma omp parallel //private(id, i, sum)
    {
        np = omp_get_num_threads();
        id = omp_get_thread_num();
    
        //#pragma omp parallel for reduction(+:sum)
        for(i = 0; i < n; i++){
            sum += a[i];
        }
            
        ftime = omp_get_wtime();
        printf("Result: %d, rank: %d, time: %f\n", sum, id, ftime - itime);

    }
	return 0;
}
