#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16
#define S_LONG 2
#define S_SHORT 1

/**
 * struct f_printf - Structure operation
 *
 * @f_printf: Function format.
 * @func: Associated function.
 */
struct f_printf
{
	char f_printf;
	int (*func)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct f_printf ptf - Structure operation
 *
 * @f_printf: Function format.
 * @ptf: Associated function.
 */
typedef struct f_printf ptf;

int _printf(const char *format, ...);
int had_toprint(const char *f_printf, int *j,
va_list ap, char buf[], int flags, int width, int precision, int size);

/* Functions to print chars and str */
int print_char(va_list genre, char buf[],
		int flags, int width, int precision, int size);
int print_string(va_list genres, char buf[],
		int flags, int width, int precision, int size);
int print_percent(va_list genres, char buf[],
		int flags, int width, int precision, int size);

/* Functions to print numbers */
int print_int(va_list genres, char buf[], int flags,
		int width, int precision, int size);
int print_binary(va_list genres, char buf[], int flags,
		int width, int precision, int size);
int print_unsigned(va_list genres, char buf[], int flags,
		int width, int precision, int size);
int print_octal(va_list genres, char buf[], int flags,
		int width, int precision, int size);
int print_hexadecimal(va_list genres, char buf[], int flags,
		int width, int precision, int size);
int print_hexa_upper(va_list genres, char buf[], int flags,
		int width, int precision, int size);
int print_hexa(va_list genres, char maptou[], char buf[],
		int flags, char flagch, int width, int precision, int size);

/* Fonctions pour ASCII */
int print_non_printable(va_list genres, char buf[],
		int flags, int width, int precision, int size);

/* fonctions pour print de memory */
int print_pointer(va_list genres, char buf[],
		int flags, int width, int precision, int size);

/* fonctions pour les specifieurs width flags prec et size */
int catch_flags(const char *format, int *j);
int catch_width(const char *format, int *j, va_list ap);
int catch_precision(const char *format, int *i, va_list ap);
int catch_size(const char *format, int *j);

/*Afficher un string inversement*/
int print_reverse(va_list genres, char buf[],
		int flags, int width, int precision, int size);

/*Afficher un string en rot 13*/
int print_rot13string(va_list genres, char buf[],
		int flags, int width, int precision, int size);

/* write handlers */
int writing_chars(char ch, char buf[], int flags,
		int width, int precision, int size);
int writing_numbers(int negatif, int index, char buf[],
		int flags, int width, int precision, int size);
int print_num(int index, char buf[], int flags,
		int width, int precision, int len, char padding, char ext);
int writing_pointers(char buf[], int index, int len,
		int width, int flags, char padding, char ext, int start_pad);
int writing_uns_num(int negatif, int index, char buf[],
		int flags, int width, int precision, int size);

/* outils */
int is_printb(char);
int append_hexa_code(char ascii, char buf[], int j);
int is_digit(char);
long int convert_s_num(long int NUM, int size);
long int convert_s_unsigned(unsigned long int NUM, int size);

#endif /* MAIN_H */
