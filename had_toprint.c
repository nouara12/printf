#include "main.h"
/**
 * had_toprint - return the arguments based on their types
 * @f_printf: the formatted string
 * @ap: our list of arguments
 * @index: diferent types of char
 * @buf: our buffer
 * @flags: our flags
 * @width: width of chars
 * @precision: specification of precision
 * @size: Size specifier
 * Return: either 1 or 2;
 */
int had_toprint(const char *f_printf, int *index, va_list ap, char buf[],
	int flags, int width, int precision, int size)
{
	int j, unk = 0, prted_ch = -1;
	ptf ptf_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (j = 0; ptf_types[j].f_printf != '\0'; j++)
		if (f_printf[*index] == ptf_types[j].f_printf)
			return (ptf_types[j].func(ap, buf, flags, width, precision, size));

	if (ptf_types[j].f_printf == '\0')
	{
		if (f_printf[*index] == '\0')
			return (-1);
		unk += write(1, "%%", 1);
		if (f_printf[*index - 1] == ' ')
			unk += write(1, " ", 1);
		else if (width)
		{
			--(*index);
			while (f_printf[*index] != ' ' && f_printf[*index] != '%')
				--(*index);
			if (f_printf[*index] == ' ')
				--(*index);
			return (1);
		}
		unk += write(1, &f_printf[*index], 1);
		return (unk);
	}
	return (prted_ch);
}

