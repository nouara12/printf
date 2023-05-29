#include "main.h"

/**
 * print_unsigned - Used to return unsigned number
 * @genres: types of char
 * @buf: the buffer
 * @flags: the flags associated
 * @width: the width
 * @precision: specification of precision
 * @size: specification of size
 * Return: Number of chars printed
 */
int print_unsigned(va_list genres, char buf[],
	int flags, int width, int precision, int size)
{
	int j = BUFF_SIZE - 2;
	unsigned long int NUM = va_arg(genres, unsigned long int);

	NUM = convert_s_unsigned(NUM, size);

	if (NUM == 0)
		buf[j--] = '0';

	buf[BUFF_SIZE - 1] = '\0';

	while (NUM > 0)
	{
		buf[j--] = (NUM % 10) + '0';
		NUM /= 10;
	}

	j++;

	return (writing_uns_num(0, j, buf, flags, width, precision, size));
}

/**
 * print_octal - Prints an unsigned number in octal notation
 * @genres: types of char
 * @buf: the buffer
 * @flags: the flags associated
 * @width: the width
 * @precision: specification of precision
 * @size: specification of size
 * Return: Number of chars printed
 */
int print_octal(va_list genres, char buf[],
	int flags, int width, int precision, int size)
{

	int j = BUFF_SIZE - 2;
	unsigned long int NUM = va_arg(genres, unsigned long int);
	unsigned long int initi_num = NUM;

	UNUSED(width);

	NUM = convert_s_unsigned(NUM, size);

	if (NUM == 0)
		buf[j--] = '0';

	buf[BUFF_SIZE - 1] = '\0';

	while (NUM > 0)
	{
		buf[j--] = (NUM % 8) + '0';
		NUM /= 8;
	}

	if (flags & F_HASH && initi_num != 0)
		buf[j--] = '0';

	j++;

	return (writing_uns_num(0, j, buf, flags, width, precision, size));
}

/**
 * print_hexadecimal - Used to print hexadecimal
 * @genres: types of char
 * @buf: the buffer
 * @flags: the flags associated
 * @width: the width
 * @precision: specification of precision
 * @size: specification of size
 * Return: Number of chars printed
 */
int print_hexadecimal(va_list genres, char buf[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(genres, "0123456789abcdef", buf,
		flags, 'x', width, precision, size));
}

/**
 * print_hexa_upper - used to print upper hexadecimal
 * @genres: types of char
 * @buf: the buffer
 * @flags: the flags associated
 * @width: the width
 * @precision: specification of precision
 * @size: specification of size
 * Return: Number of chars printed
 */
int print_hexa_upper(va_list genres, char buf[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(genres, "0123456789ABCDEF", buf,
		flags, 'X', width, precision, size));
}

/**
 * print_hexa - used to print lower or upper hex
 * @genres: types of char
 * @maptou: values mapped to the number
 * @buf: our buffer
 * @flags: the flags associated
 * @flagch: Calcul des flags actifs
 * @width: the width
 * @precision: specification of precision
 * @size: specification of size
 * Return: Number of chars printed
 */
int print_hexa(va_list genres, char maptou[], char buf[],
	int flags, char flagch, int width, int precision, int size)
{
	int j = BUFF_SIZE - 2;
	unsigned long int NUM = va_arg(genres, unsigned long int);
	unsigned long int initi_num = NUM;

	UNUSED(width);

	NUM = convert_s_unsigned(NUM, size);

	if (NUM == 0)
		buf[j--] = '0';

	buf[BUFF_SIZE - 1] = '\0';

	while (NUM > 0)
	{
		buf[j--] = maptou[NUM % 16];
		NUM /= 16;
	}

	if (flags & F_HASH && initi_num != 0)
	{
		buf[j--] = flagch;
		buf[j--] = '0';
	}

	j++;

	return (writing_uns_num(0, j, buf, flags, width, precision, size));
}
