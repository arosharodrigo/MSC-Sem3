/**
 * DAXPY test to check floating point performance.
 *
 * @author Dilum Bandara, CSE, UoM
 * @since 2014-10-01
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>  

const double a = 3.141;	//scaler

/*
 * Structure ho hold x & y values of an element
 */
struct values {
   double x;
   double y;
};


typedef struct values Values;


/** 
 * Populate element with random values
 * v - Pointer to array of values structures
 * n - No of elements in array
 */
void populateS(Values *v, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		v[i].x = ((double)rand()/(double)RAND_MAX);
		v[i].y = ((double)rand()/(double)RAND_MAX);
	}
}


/** 
 * Calculate Double AX plus Y, i.e., y[i] = a * x[i] + y[i]
 * v - Pointer to array of values structures
 * a - Scalar value
 * n - No of elements in array
 */

void daxpyS(Values *v, double a, int n) {
	int i;

	for (i = 0; i < n; i++) 
		v[i].y = a*v[i].x + v[i].y; //y[i] = a * x[i] + y[i]
}


void main(int argc, char **argv)
{
	Values *v;
	int n, r, i;
	struct timeval tStart1, tStart2, tEnd;

	if (argc != 3)
	{
		printf("Incorrect arguments. Usage: %s size-of-vector rounds\n", argv[0]);
		exit(0);
	}
	n = atoi(argv[1]);
	r = atoi(argv[2]);

	gettimeofday(&tStart1, NULL);				//Start timer 1

	v = malloc(n * sizeof(Values));				//Array of structures	
	populateS(v, n);							//Populate X & Y random values

	gettimeofday(&tStart2, NULL);				//Start timer 2

	//printf("%f\n", v[0].x);
	//printf("%f\n", v[0].y);

	for (i = 0; i < r; i++)						//Call daxpy r rounds
	{
		daxpyS(v, a , n);
	}

	//printf("%f\n", v[0].x);
	//printf("%f\n", v[0].y);

	gettimeofday(&tEnd, NULL);
    printf("Execution Time1:%fs\n", (tEnd.tv_sec - tStart1.tv_sec) + (tEnd.tv_usec - tStart1.tv_usec)/1000000.0);
    printf("Execution Time2:%fs\n", (tEnd.tv_sec - tStart2.tv_sec) + (tEnd.tv_usec - tStart2.tv_usec)/1000000.0);

	free(v);									//Deallocate memory

	return;
}
