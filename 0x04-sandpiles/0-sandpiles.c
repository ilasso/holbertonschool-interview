#include <stdio.h>
#include "sandpiles.h"
/**
 *printgrid - function to display a grid
 *@grid: grid to display
 *Return: void
 */
void printgrid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
/**
 *sandpiles_sum - function that computes the sum of two sandpiles
 *@grid1: grid a
 *@grid2: grid b
 *Return: void
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int suma = 0,  i, count = 3, j, unstable = 0;
	int grid3[3][3], grid4[3][3], suma1, suma2, suma3, suma4;

	for (i = 0; i < count; i++) /* SUMM  TWO GRIDS */
	{
		for (j = 0; j < count; j++)
		{
			grid3[i][j] =  grid1[i][j] + grid2[i][j];
		} /* for */
	} /* for */
	for (i = 0; i < count; i++)
	{
		for (j = 0; j < count; j++)
		{
			grid1[i][j] =  grid3[i][j];
			if (grid1[i][j] > 3)
			{
				unstable = 1;
				grid4[i][j] = 1;
			}
			else
				grid4[i][j] = 0;
		} /* for */
	} /* for */
	if (!unstable)
		return;
	printf("=\n");
	printgrid(grid1);
	unstable = 1;
	while (unstable)
	{
		unstable = 0;
		for (i = 0; i < count; i++)
		{
			for (j = 0; j < count; j++)
			{
				if (grid3[i][j] > 3)
				{
					grid3[i][j] = grid3[i][j] - 4;
					grid4[i][j] = 1;
				}
				else
					grid4[i][j] = 0;
			} /* for */
		} /* for */
		for (i = 0; i < count; i++)
		{
			for (j = 0; j < count; j++)
			{
				suma1 = SUMA1(i, j);
				suma2 = SUMA2(i, j);
				suma3 = SUMA3(i, j);
				suma4 = SUMA4(i, j);
				suma = suma1 + suma2 + suma3 + suma4;
				grid1[i][j] =  grid3[i][j] + suma;
				grid3[i][j] =  grid1[i][j];
				if (grid3[i][j] > 3)
					unstable = 1;
			} /* for */
		} /* for */
		if (unstable == 0)
			break;
		printf("=\n");
		printgrid(grid1);
	} /*while*/
}
