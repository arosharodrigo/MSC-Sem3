/**
 * Random number generation example.
 *
 * @author Dilum Bandara, CSE, UoM
 * @since 2014-09-30
 *
 */


#include <stdio.h>
#include <stdlib.h>

void main()
{
	int i;
	for(i = 0; i < 5; i++)
		printf("%d\n", rand());
}
