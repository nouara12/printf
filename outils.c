#include "main.h"

/**
 * is_printb - Used pour evaluer les char
 * @ch: en evaluation
 *
 * Return: 1 ou 0
 */
int is_printb(char ch)
{
	if (ch >= 32 && ch < 127)
		return (1);
	return (0);
}

/**
 * append_hexa_code - pour ascii code
 * @buf: our buffer
 * @j: index
 * @ascii: code ascii
 * Return: Always 3
 */
int append_hexa_code(char ascii, char buf[], int j)
{
	char maptou[] = "0123456789ABCDEF";

	if (ascii < 0)
		ascii *= -1;

	buf[j++] = '\\';
	buf[j++] = 'x';

	buf[j++] = maptou[ascii / 16];
	buf[j++] = maptou[ascii % 16];

	return (3);
}

/**
 * is_digit - verifie si char est digit
 * @ch: evalue
 *
 * Return: 1 ou 0
 */
int is_digit(char ch)
{
	if (ch >= '0' && ch <= '9')
		return (1);
	return (0);
}

/**
 * convert_s_num - yo7awil num to type dialo
 * @NUM: num li7na dawin 3lih
 * @size: size dialo
 *
 * Return: wik wik a3ibad lah
 */
long int convert_s_num(long int NUM, int size)
{
	if (size == S_LONG)
		return (NUM);
	else if (size == S_SHORT)
		return ((short)NUM);
	return ((int)NUM);
}

/**
 * convert_s_unsigned - yo7awil num l type dialo
 * @NUM: num li7na dawin 3lih
 * @size: size dialo
 *
 * Return: wik wik a3ibad lah
 */
long int convert_s_unsigned(unsigned long int NUM, int size)
{
	if (size == S_LONG)
		return (NUM);
	else if (size == S_SHORT)
		return ((unsigned short)NUM);
	return ((unsigned int)NUM);
}
