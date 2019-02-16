#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int i;     // counter for loops
	int n;     // total elements
	int d;     // counter for dimensions
	int dim;   // total dimensions
	int w;     // range of element's values
	int a = 1; // use for random generate elements

	srand(time(NULL));

	printf("\n GENERATE POSITIVE RANDOM ELEMENTS ");
	printf("\n Choose the range of elements values : 1 to ");
	scanf("%d",&w);
	printf("\n Choose the amount of elements : ");
	scanf("%d",&n);
	printf("\n Choose the amount of dimensions : ");
	scanf("%d",&dim);

/*----------------------------------------------------------------------------*/
	// Memory Allocation

	double **GenerateRandomElements;  // Array of Elements n
	GenerateRandomElements = calloc(n, sizeof(double));
	for (d = 0; d < n; d++)
	    GenerateRandomElements[d] = calloc(dim, sizeof(double *));

/*----------------------------------------------------------------------------*/

	for (i = 0; i < n; i++)
	{
	   for (d = 0; d < dim; d++)
	   GenerateRandomElements[i][d] = rand() % (w - a + 1) + a;
  }

    FILE *G_RANDOM;  // The name of the output csv file
    G_RANDOM = fopen("RandomElements.txt","w");
    for (i = 0; i < n; i++)
    {
      for (d = 0; d < dim; d++)
	     {
            fprintf(G_RANDOM,"%lf", GenerateRandomElements[i][d]);
            if(d < dim-1)
            fprintf(G_RANDOM, "\t");
         }
          fprintf(G_RANDOM, "\n");
    }

free(GenerateRandomElements);
fclose(G_RANDOM);

return 0;
}
