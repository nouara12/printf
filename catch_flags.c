#include "main.h"

/**
 * catch_flags - Calculates active flags
 * @format: strings that are formatted
 * @j: a parameter
 * Return: flags
 */
int catch_flags(const char *format, int *j)
{
	int k, c;
	int flags = 0;
	const char flags_char[] = {'-', '+', '0', '#', ' ', '\0'};
	const int flags_array[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (c = *j + 1; format[c] != '\0'; c++)
	{
		for (k = 0; flags_char[k] != '\0'; k++)
			if (format[c] == flags_char[k])
			{
				flags |= flags_array[k];
				break;
			}

		if (flags_char[k] == 0)
			break;
	}

	*j = c - 1;

	return (flags);
}

