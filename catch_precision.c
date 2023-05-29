#include "main.h"

/**
 * catch_precision - Calculates la precision
 * @format: format
 * @j: arguments a afficher
 * @ap: liste des arguments.
 *
 * Return: la precisiooooon
 */
int catch_precision(const char *format, int *j, va_list ap)
{
	int c = *j + 1;
	int precision = -1;

	if (format[c] != '.')
		return (precision);

	precision = 0;

	for (c += 1; format[c] != '\0'; c++)
	{
		if (is_digit(format[c]))
		{
			precision *= 10;
			precision += format[c] - '0';
		}
		else if (format[c] == '*')
		{
			c++;
			precision = va_arg(ap, int);
			break;
		}
		else
			break;
	}

	*j = c - 1;

	return (precision);
}
