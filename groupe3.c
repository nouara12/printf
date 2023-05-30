#include "main.h"

/**
 * print_pointer - Used to print a value of pointer
 * @genres: types of char
 * @buf: the buffer
 * @flags: the flags associated
 * @width: the width
 * @precision: specification of precision
 * @size: specification of size
 * Return: chars printed
 */
int print_pointer(va_list genres, char buf[],
		int flags, int width, int precision, int size)
{
	char ext = 0, padding = ' ';
	int index = BUFF_SIZE - 2, len = 2, start_pad = 1;
	unsigned long num_add;
	char maptou[] = "0123456789abcdef";
	void *adresse = va_arg(genres, void *);

	UNUSED(width);
	UNUSED(size);

	if (adresse == NULL)
		return (write(1, "(nil)", 5));

	buf[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_add = (unsigned long)adresse;

	while (num_add > 0)
	{
		buf[index--] = maptou[num_add % 16];
		num_add /= 16;
		len++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padding = '0';
	if (flags & F_PLUS)
		ext = '+', len++;
	else if (flags & F_SPACE)
		ext = ' ', len++;
	index++;
	return (writing_pointers(buf, index, len,
				width, flags, padding, ext, start_pad));
}

/**
 * print_non_printable - Used to print ASCII of char
 * @genres: types of char
 * @buf: the buffer
 * @flags: the flags associated
 * @width: the width
 * @precision: specification of precision
 * @size: specification of size
 * Return: Number of chars printed
 */
int print_non_printable(va_list genres, char buf[],
		int flags, int width, int precision, int size)
{
	int j = 0, cardib = 0;
	char *strg = va_arg(genres, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (strg == NULL)
		return (write(1, "(null)", 6));

	while (strg[j] != '\0')
	{
		if (is_printb(strg[j]))
			buf[j + cardib] = strg[j];
		else
			cardib += append_hexa_code(strg[j], buf, j + cardib);
<<<<<<< HEAD

=======
>>>>>>> e976ed371b195c1f62c6216b0e3d0e244d0e8d79
		j++;
	}
	buf[j + cardib] = '\0';
<<<<<<< HEAD

=======
>>>>>>> e976ed371b195c1f62c6216b0e3d0e244d0e8d79
	return (write(1, buf, j + cardib));
}

/**
 * print_reverse - Prints reverse string.
 * @genres: types of char
 * @buf: the buffer
 * @flags: the flags associated
 * @width: the width
 * @precision: specification of precision
 * @size: specification of size
 * Return: Numbers of chars printed
 */
int print_reverse(va_list genres, char buf[],
		 int flags, int width, int precision, int size)
{
	char *strg;
	int j, compt = 0;

	UNUSED(buf);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	strg = va_arg(genres, char *);

	if (strg == NULL)
	{
		UNUSED(precision);
		strg = ")Null(";
	}
	for (j = 0; strg[j]; j++)
		;
	for (j = j - 1; j >= 0; j--)
	{
		char m = strg[j];

		write(1, &m, 1);
		compt++;
	}
	return (compt);
}

/**
 * print_rot13string - Used to print rot13 string.
 * @genres: types of char
 * @buf: the buffer
 * @flags: the flags associated
 * @width: the width
 * @precision: specification of precision
 * @size: specification of size
 * Return: Numbers of chars printed
 */
int print_rot13string(va_list genres, char buf[],
		int flags, int width, int precision, int size)
{
	char x;
	char *strg;
	unsigned int j, k;
	int compt = 0;
	char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char output[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	strg = va_arg(genres, char *);
	UNUSED(buf);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (strg == NULL)
		strg = "(AHYY)";
	for (j = 0; strg[j]; j++)
	{
		for (k = 0; input[k]; k++)
		{
			if (input[k] == strg[j])
			{
				x = output[k];
				write(1, &x, 1);
				compt++;
				break;
			}
		}
		if (!input[k])
		{
			x = strg[j];
			write(1, &x, 1);
			compt++;
		}
	}
	return (compt);
}
