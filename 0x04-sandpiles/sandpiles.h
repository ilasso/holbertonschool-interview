#ifndef SANDPILES
#define SANDPILES

#define SUMA1(i, j) (((i - 1) >= 0) ? grid4[i - 1][j] : 0)
#define SUMA2(i, j) (((i + 1) >= 0 && ((i + 1) < 3)) ? grid4[i + 1][j] : 0)
#define SUMA3(i, j) (((j + 1) >= 0 && ((j + 1) < 3)) ? grid4[i][j + 1] : 0)
#define SUMA4(i, j) (((j - 1) >= 0) ? grid4[i][j - 1] : 0)

void printgrid(int grid[3][3]);
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);

#endif /*SANDPILES*/
