#include <unistd.h>
#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * Perror - print Error with putchar.
 * Return: Always 0.
 */
void Perror(void)
{
	_putchar('E');
	_putchar('r');
	_putchar('r');
	_putchar('o');
	_putchar('r');
	_putchar('\n');
	exit(98);
}
/**
 * numero - check if strings have only numbers.
 * @s: string 1
 * @a: string 2
 * Return: Always 1 if not or 0 if only has number.
 */
void numero(char *s, char *a)
{
	int i = 0, aux = 0;

	while (s[i] != '\0')
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
		{
			aux = 1;
			break;
		}
		i++;
	}
	i = 0;
	while (a[i] != '\0')
	{
		if (!(a[i] >= '0' && a[i] <= '9'))
		{
			aux = 1;
			break;
		}
		i++;
	}
	if (aux == 1)
		Perror();
	if (*s == '0' || *a == '0')
	{
		_putchar('0');
		_putchar('\n');
		exit(0);
	}
}
/**
 * impresion - print the pointer
 * @s: string.
 * @a: size of string
 */
void impresion(char *s, int a)
{
	int i;

	for (i = 0; i < a; i++)
	{
		if (!(s[0] == '0' && i == 0))
			_putchar(s[i]);
	}
	_putchar('\n');
}

/**
 * tama - give the size
 * @s: string of numbers
 * Return: size
 */
int tama(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
