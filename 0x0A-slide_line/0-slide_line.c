#include <stdlib.h>
#include "slide_line.h"

/**
 * swap - swap numbers
 * @l: pointer in array number one
 * @r: pointer in array number two
 */
void swap(int *l, int *r)
{
	int temp = *l;

	*l = *r;
	*r = temp;
}

/**
 * left - move array to the left
 * @line: array of integers.
 * @size: size of the array
 */
void left(int *line, size_t size)
{
	size_t i, pos = 0;

	for (i = 0; i < size && pos < size; i++)
	{
		while (line[pos] == 0 && pos < size && pos + 1 < size)
			pos++;
		if (!line[i])
			swap(&line[pos], &line[i]);
		pos++;
	}
}

/**
 * right - move array to the right
 * @line: array of integers.
 * @size: size of the array
 */
void right(int *line, size_t size)
{
	size_t i;
	size_t pos = size - 1;

	for (i = size - 1; (int) i >= 0 && (int) pos >= 0; i--)
	{
		while (line[pos] == 0 && (int) pos > 0)
			pos--;
		if (!line[i])
			swap(&line[pos], &line[i]);
		pos--;
	}
}

/**
 * slide_line - function that slides and merges
 *              an array of integers like 2048 game
 * @line: array
 * @size: size
 * @direction: right or left
 * Return: return 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
	size_t i = 0;

	if (direction == SLIDE_LEFT)
	{
		left(line, size);
		for (i = 0; i < size; i++)
		{
			if (line[i] == line[i + 1])
			{
				line[i] = line[i] + line[i + 1];
				line[i + 1] = 0;
			}
		}
		left(line, size);
		return (1);
	}

	if (direction == SLIDE_RIGHT)
	{
		right(line, size);
		for (i = size - 1; (int) i >= 0; i--)
		{
			if (line[i] == line[i - 1])
			{
				line[i] = line[i] + line[i - 1];
				line[i - 1] = 0;
			}
		}
		right(line, size);
		return (1);
	}
	return (0);
}
