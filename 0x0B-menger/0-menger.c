#include "menger.h"

/**
 * menger - prints menger sponge
 * @level: levels to print
 */
void menger(int level)
{
	int col, row, size;

	if (level >= 0)
	{
		size = pow(3, level);
		for (col = 0; col < size; col++)
		{
			for (row = 0; row < size; row++)
				printf("%c", printPosition(col, row));
			printf("\n");
		}
	}
}

/**
 * printPosition - prints a '#' or a ' '
 * @col: input column
 * @row: input row
 * Return: '#' or ' '
 */
char printPosition(int col, int row)
{
	for (; col && row; col /= 3, row /= 3)
		if (col % 3 == 1 && row % 3 == 1)
			return (' ');
	return ('#');
}
