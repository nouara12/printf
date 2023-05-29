#include "main.h"

/**
 * catch_size - Returns size of arguments
 * @format: format
 * @j: arguments a afficher
 *
 * Return: size
 */
int catch_size(const char *format, int *j)
{
	int c = *j + 1;
	int size = 0;

	if (format[c] == 'l')
		size = S_LONG;
	else if (format[c] == 'h')
		size = S_SHORT;

	if (size == 0)
		*j = c - 1;
	else
		*j = c;

	return (size);
}

