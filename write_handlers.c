#include "main.h"

/**
 * writing_chars - Prints a string
 * @ch: type char.
 * @buf: Buffer to display the array
 * @flags: active flags to calculate
 * @width: getting the width
 * @precision: specifier for precision
 * @size: specifier for size
 *
 * Return: the output of main file.
 */
int writing_chars(char ch, char buf[],
<<<<<<< HEAD
	int flags, int width, int precision, int size)
=======
		 int flags, int width, int precision, int size)
>>>>>>> e976ed371b195c1f62c6216b0e3d0e244d0e8d79
{
	int j = 0;
	char padding = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		padding = '0';

	buf[j++] = ch;
	buf[j] = '\0';

	if (width > 1)
	{
		buf[BUFF_SIZE - 1] = '\0';
		for (j = 0; j < width - 1; j++)
			buf[BUFF_SIZE - j - 2] = padding;

		if (flags & F_MINUS)
			return (write(1, &buf[0], 1) +
					write(1, &buf[BUFF_SIZE - j - 1], width - 1));
		else
			return (write(1, &buf[BUFF_SIZE - j - 1], width - 1) +
					write(1, &buf[0], 1));
	}

	return (write(1, &buf[0], 1));
}


/**
 * writing_numbers - returns a string format
 * @negatif: list of arguments
 * @index: diferent types of char.
 * @buf: buffer used to print
 * @flags: active flags to calculate
 * @width: getting the width
 * @precision: specifier for precision
 * @size: specifier for size
 *
 * Return: Number of chars printed.
 */
int writing_numbers(int negatif, int index, char buf[],
<<<<<<< HEAD
	int flags, int width, int precision, int size)
=======
		int flags, int width, int precision, int size)
>>>>>>> e976ed371b195c1f62c6216b0e3d0e244d0e8d79
{
	int len = BUFF_SIZE - index - 1;
	char padding = ' ', ext = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padding = '0';
	if (negatif)
		ext = '-';
	else if (flags & F_PLUS)
		ext = '+';
	else if (flags & F_SPACE)
		ext = ' ';

	return (print_num(index, buf, flags, width, precision,
<<<<<<< HEAD
		len, padding, ext));
=======
				len, padding, ext));
>>>>>>> e976ed371b195c1f62c6216b0e3d0e244d0e8d79
}

/**
 * print_num - Prints a number using buf
 * @index: index in which the number is starting
 * @buf: our buffer
 * @flags: the flags used
 * @width: the width of the buffer
 * @precision: the specifier for precision
 * @len: numbers' total length
 * @padding: char's padding
 * @ext: char (extra)
 *
 * Return: chars printed.
 */
int print_num(int index, char buf[],
<<<<<<< HEAD
	int flags, int width, int precision,
	int len, char padding, char ext)
{
	int j, start_pad = 1;

	if (precision == 0 && index == BUFF_SIZE - 2 && buf[index] == '0' && width == 0)
=======
		int flags, int width, int precision,
		int len, char padding, char ext)
{
	int j, start_pad = 1;

	if (precision == 0 && index == BUFF_SIZE - 2 &&
			buf[index] == '0' && width == 0)
>>>>>>> e976ed371b195c1f62c6216b0e3d0e244d0e8d79
		return (0);
	if (precision == 0 && index == BUFF_SIZE - 2 && buf[index] == '0')
		buf[index] = padding = ' ';
	if (precision > 0 && precision < len)
		padding = ' ';
	while (precision > len)
		buf[--index] = '0', len++;
	if (ext != 0)
		len++;
	if (width > len)
	{
		for (j = 1; j < width - len + 1; j++)
			buf[j] = padding;
		buf[j] = '\0';
		if (flags & F_MINUS && padding == ' ')
		{
			if (ext)
				buf[--index] = ext;
			return (write(1, &buf[index], len) + write(1, &buf[1], j - 1));
		}
		else if (!(flags & F_MINUS) && padding == ' ')
		{
			if (ext)
				buf[--index] = ext;
			return (write(1, &buf[1], j - 1) + write(1, &buf[index], len));
		}
		else if (!(flags & F_MINUS) && padding == '0')
		{
			if (ext)
				buf[--start_pad] = ext;
			return (write(1, &buf[start_pad], j - start_pad) +
<<<<<<< HEAD
				write(1, &buf[index], len - (1 - start_pad)));
=======
					write(1, &buf[index], len - (1 - start_pad)));
>>>>>>> e976ed371b195c1f62c6216b0e3d0e244d0e8d79
		}
	}
	if (ext)
		buf[--index] = ext;
	return (write(1, &buf[index], len));
}

/**
 * writing_uns_num - prints an unsigned number
 * @negatif: indicates negative numbers
 * @index: index in which the number is starting
 * @buf: our buffer
 * @flags: the flags used
 * @width: the width of the buffer
 * @precision: the specifier for precision
 * @size: the specifier for size
 *
 * Return: the chars written.
 */
int writing_uns_num(int negatif, int index,
		char buf[], int flags, int width, int precision, int size)
{
	int len = BUFF_SIZE - index - 1, j = 0;
	char padding = ' ';

	UNUSED(negatif);
	UNUSED(size);

	if (precision == 0 && index == BUFF_SIZE - 2 && buf[index] == '0')
		return (0);

	if (precision > 0 && precision < len)
		padding = ' ';

	while (precision > len)
	{
		buf[--index] = '0';
		len++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padding = '0';

	if (width > len)
	{
		for (j = 0; j < width - len; j++)
			buf[j] = padding;

		buf[j] = '\0';

		if (flags & F_MINUS)
		{
			return (write(1, &buf[index], len) + write(1, &buf[0], j));
		}
		else
		{
			return (write(1, &buf[0], j) + write(1, &buf[index], len));
		}
	}
<<<<<<< HEAD

=======
>>>>>>> e976ed371b195c1f62c6216b0e3d0e244d0e8d79
	return (write(1, &buf[index], len));
}

/**
 * writing_pointers - Allocates memory address
 * @buf: our buffer
 * @index: index in which the number is starting
 * @len: number's length
 * @width: specifier for width
 * @flags: specifier for flags
 * @padding: representation of char's padding
 * @ext: extra char
 * @start_pad: the start of padding (index)
 *
 * Return: Char written.
 */
int writing_pointers(char buf[], int index, int len,
		 int width, int flags, char padding, char ext, int start_pad)
{
	int j;

	if (width > len)
	{
		for (j = 3; j < width - len + 3; j++)
			buf[j] = padding;
		buf[j] = '\0';
		if (flags & F_MINUS && padding == ' ')
		{
			buf[--index] = 'x';
			buf[--index] = '0';
			if (ext)
				buf[--index] = ext;
			return (write(1, &buf[index], len) + write(1, &buf[3], j - 3));
		}
		else if (!(flags & F_MINUS) && padding == ' ')
		{
			buf[--index] = 'x';
			buf[--index] = '0';
			if (ext)
				buf[--index] = ext;
			return (write(1, &buf[3], j - 3) + write(1, &buf[index], len));
		}
		else if (!(flags & F_MINUS) && padding == '0')
		{
			if (ext)
				buf[--start_pad] = ext;
			buf[1] = '0';
			buf[2] = 'x';
			return (write(1, &buf[start_pad], j - start_pad) +
<<<<<<< HEAD
				write(1, &buf[index], len - (1 - start_pad) - 2));
=======
					write(1, &buf[index], len - (1 - start_pad) - 2));
>>>>>>> e976ed371b195c1f62c6216b0e3d0e244d0e8d79
		}
	}
	buf[--index] = 'x';
	buf[--index] = '0';
	if (ext)
		buf[--index] = ext;
	return (write(1, &buf[index], BUFF_SIZE - index - 1));
}
