#include <stdio.h>
#include "palindrome.h"
#include <string.h>
#include <stdlib.h>
/**
 *is_palindrome - function that checks whether or not a
 *		  given unsigned integer is a palindrome.
 *@n: is the number to be checked
 *Return: return 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{

	unsigned long dig, number;
	char digitsA[20];
	char digitsB[20];
	int count = 0;
	int i = 0;

	number = n;
	while (number >= 1)
	{
		dig = number % 10;
		number = number / 10;
		digitsB[count] = dig + '0';
		count++;
	}
	digitsB[count] = '\0';

	for (i = 0; i < (int) strlen(digitsB); i++)
	{
		digitsA[i] = digitsB[count - 1];
		count--;
	}

	digitsA[i] = '\0';

	for (i = 0 ; i < (int) strlen(digitsB); i++)
	{
		if ((digitsB[i]) != digitsA[i])
			return (0);
	}
	return (1);
}
