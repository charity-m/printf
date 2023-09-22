#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
/**
 * struct spec -structure specifier
 * @specifier: the conversion specifier
 * @v: function pointer
 */

typedef struct specifiers
{
	char *specifier;
	int (*v)(va_list args);
} spc_dt;

int _printf(const char *format, ...);
int ptcha(char c);
int prnt_char(va_list args);
int prnt_strng(va_list args);
int prnt_frmt(const char *format, va_list args);
int prnt_spec(char format, va_list args);
int prnt_invalid(char prev_format, char format, int count);
int prnt_integ(va_list args);
void recursion_integ(int r);
int prnt_int_binary(va_list args);
void recursion_int_binary(int a);
int valid_char(char _type);

#endif
