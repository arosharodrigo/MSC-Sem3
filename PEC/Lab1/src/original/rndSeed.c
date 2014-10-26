/**
 * Random number generation with seed example.
 *
 * @author Dilum Bandara, CSE, UoM
 * @since 2014-09-23
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>  

void main()
{
	int i;

	srand(time(NULL));

	for(i = 0; i < 5; i++)
		printf("%d\n", rand());
}
