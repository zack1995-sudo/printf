#include "main.h"

/**
 * _puts - prints a string followed by newline
 * @str: string
 * Return: void
*/

int _puts(char *str)
{
	char *a = str;

	while (*str)
		_putchar(*str++);
	return (str - a);
}

/**
 * _putchar - writes the character  to stdout
 * @c: character
 * Return: on success 1
 * on error, 1 is returned, and errno is set appropriately.
*/

int _putchar(int c)
{
	static int i;

	static char buf(OUTPUT_BUF_SIZE);

	if (c == BUF_FLUSH || i >= OUTPUT_BUF_SIZE)
	{
		Write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
