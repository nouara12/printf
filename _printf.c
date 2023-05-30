#include "main.h"

void p_buf(char buf[], int *buf_index);

/**
 * _printf - our made printf function
 * @format: format for printf.
 * Return: chars.
 */
int _printf(const char *format, ...)
{
	int j, prted = 0, prted_ch = 0;
	int flags, width, precision, size, buf_index = 0;
	va_list ap;
	char buf[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(ap, format);

	for (j = 0; format && format[j] != '\0'; j++)
	{
		if (format[j] != '%')
		{
			buf[buf_index++] = format[j];
			if (buf_index == BUFF_SIZE)
				p_buf(buf, &buf_index);
			/* write(1, &format[i], 1);*/
			prted_ch++;
		}
		else
		{
			p_buf(buf, &buf_index);
			flags = catch_flags(format, &j);
			width = catch_width(format, &j, ap);
			precision = catch_precision(format, &j, ap);
			size = catch_size(format, &j);
			++j;
			prted = had_toprint(format, &j, ap, buf,
<<<<<<< HEAD
				flags, width, precision, size);
=======
					flags, width, precision, size);
>>>>>>> e976ed371b195c1f62c6216b0e3d0e244d0e8d79
			if (prted == -1)
				return (-1);
			prted_ch += prted;
		}
	}
	p_buf(buf, &buf_index);
	va_end(ap);
	return (prted_ch);
}

/**
 * p_buf - returns the content of buf
 * @buf: buffer of chars
 * @buf_index: length of buff
 */
void p_buf(char buf[], int *buf_index)
{
	if (*buf_index > 0)
		write(1, &buf[0], *buf_index);
	*buf_index = 0;
}
