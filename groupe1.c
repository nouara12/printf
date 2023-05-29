#include "main.h"

/************************* PRINT CHAR *************************/

/**
 * print_char - Used to print a char
 * @genres: types of char
 * @buf: the buffer
 * @flags: the flags associated
 * @width: the width
 * @precision: specification of precision
 * @size: specification of size
 * Return: chars printed
 */
int print_char(va_list genres, char buf[],
	int flags, int width, int precision, int size)
{
	char ch = va_arg(genres, int);

	return (writing_chars(ch, buf, flags, width, precision, size));
}

/**
 * print_string - Used to print a string
 * @genres: types of char
 * @buf: the buffer
 * @flags: the flags associated
 * @width: the width
 * @precision: specification of precision
 * @size: specification of size
 * Return: chars printed
 */
int print_string(va_list genres, char buf[],
	int flags, int width, int precision, int size)
{
	int len = 0, j;
	char *strg = va_arg(genres, char *);

	UNUSED(buf);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (strg == NULL)
	{
		strf = "(null)";
		if (precision >= 6)
			strg = "      ";
	}

	while (strg[len] != '\0')
		len++;

	if (precision >= 0 && precision < len)
		len = precision;

	if (width > len)
	{
		if (flags & F_MINUS)
		{
			write(1, &strg[0], len);
			for (j = width - len; j > 0; j--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (j = width - len; j > 0; j--)
				write(1, " ", 1);
			write(1, &strg[0], len);
			return (width);
		}
	}

	return (write(1, strg, len));
}

/**
 * print_percent - Used to print a percent
 * @genres: types of char
 * @buf: the buffer
 * @flags: the flags associated
 * @width: the width
 * @precision: specification of precision
 * @size: specification of size
 * Return: Number of chars printed
 */
int print_percent(va_list genres, char buf[],
	int flags, int width, int precision, int size)
{
	UNUSED(genres);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/************************* PRINT INT *************************/
/**
 * print_int - Print int
 * @genres: types of char
 * @buf: the buffer
 * @flags: the flags associated
 * @width: the width
 * @precision: specification of precision
 * @size: specification of size
 * Return: Number of chars printed
 */
int print_int(va_list genres, char buf[],
	int flags, int width, int precision, int size)
{
	int j = BUFF_SIZE - 2;
	int negatif = 0;
	long int N = va_arg(genres, long int);
	unsigned long int NUM;

	nN = convert_s_num(n, size);

	if (N == 0)
		buf[j--] = '0';

	buf[BUFF_SIZE - 1] = '\0';
	NUM = (unsigned long int)N;

	if (N < 0)
	{
		NUM = (unsigned long int)((-1) * N);
		negatif = 1;
	}

	while (NUM > 0)
	{
		buf[j--] = (NUM % 10) + '0';
		NUM /= 10;
	}

	ij++;

	return (writing_numbers(negatif, j, buf, flags, width, precision, size));
}

/************************* PRINT BINARY *************************/
/**
 * print_binary - print binary
 * @genres: types of char
 * @buf: the buffer
 * @flags: the flags associated
 * @width: the width
 * @precision: specification of precision
 * @size: specification of size
 * Return: Number of chars printed
 */
int print_binary(va_list genres, char buf[],
	int flags, int width, int precision, int size)
{
	unsigned int a, b, j, SUM;
	unsigned int A[32];
	int compt;

	UNUSED(buf);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	a = va_arg(genres, unsigned int);
	b = 2147483648;
	A[0] = a / b;
	for (j = 1; j < 32; j++)
	{
		b /= 2;
		A[j] = (a / b) % 2;
	}
	for (j = 0, SUM = 0, compt = 0; j < 32; j++)
	{
		SUM += A[j];
		if (SUM || j == 31)
		{
			char m = '0' + A[j];

			write(1, &m, 1);
			compt++;
		}
	}
	return (compt);
}
