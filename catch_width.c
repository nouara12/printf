#include "main.h"

/**
 * catch_width - return the width from print
 * @format: format
 * @j: Liste des arguments a printer
 * @ap: liste des arguments
 *
 * Return: la taille
 */
int catch_width(const char *format, int *j, va_list ap)
{
	int c;
	int width = 0;

	for (c = *j + 1; format[c] != '\0'; c++)
	{
		if (is_digit(format[c]))
		{
			width *= 10;
			width += format[c] - '0';
		}
		else if (format[c] == '*')
		{
			c++;
			width = va_arg(ap, int);
			break;
		}
		else
			break;
	}

	*j = c - 1;

	return (width);
}

