#include <stdlib.h>
#include <stdio.h>
#include "sandpiles.h"

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

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
  (void) (grid1);
  (void) (grid2);

  int suma = 0,  i, count = 3, j, unstable = 0, a;
  int suma1, suma2, suma3, suma4;
  int grid3[3][3];
  int grid4[3][3];
  int n;

  (void) (n);
  (void) (a);

  /* SUMAR LAS DOS MATRICES*/
  for (i = 0; i < count; i++) {
    for (j = 0; j < count; j++) {
      grid3[i][j] =  grid1[i][j] + grid2[i][j];
    } /* for */
  } /* for */

  for (i = 0; i < count; i++) {
    for (j = 0; j < count; j++) {
      /*printf("grid1=%d\n",grid3[i][j]);*/
      grid1[i][j] =  grid3[i][j];

      if (grid1[i][j] > 3) {
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
while (unstable) {
  unstable = 0;
  for (i = 0; i < count; i++) {
    for (j = 0; j < count; j++) {
      if (grid3[i][j] > 3 ) {
        grid3[i][j] = grid3[i][j] - 4;
        grid4[i][j] = 1;
        }
        else
        grid4[i][j] = 0;
    } /* for */
  } /* for */


  for (i = 0; i < count; i++) {
    for (j = 0; j < count; j++) {
      suma1 = ((i - 1) >= 0) ? grid4[i - 1][j]:0 ;
      suma2 = ((i + 1) >= 0 && ((i+1) < 3)) ? grid4[i + 1][j]:0 ;
      suma3 = ((j + 1) >= 0 && ((j+1) < 3)) ? grid4[i][j + 1]:0 ;
      suma4 = ((j - 1) >= 0) ? grid4[i][j - 1]:0 ;
      suma = suma1 + suma2 + suma3 + suma4;
      /*printf("i=%d,j=%d,suma1=%d,suma2=%d,suma3=%d,suma4=%di,total=%d\n", i,j,suma1,suma2,suma3,suma4,suma1+suma2+suma3+suma4 );*/
      grid1[i][j] =  grid3[i][j] + suma;
      grid3[i][j] =  grid1[i][j];
      if (grid3[i][j] > 3)
        unstable = 1;
    } /* for */
  } /* for */

  /*n = scanf("%d", &a);*/
  if (unstable == 0)
    break;
  else {
    printf("=\n");
    printgrid(grid1);
  }

} /*while*/
}
