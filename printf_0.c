#include "main.h"
/**
 * _printf - custom like printf function
 * @format: a string containing format specifiers
 * Return: number of bytes
 */
int _printf(const char *format, ...)
{
	va_list args;
	int len = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	len = prnt_frmt(format, args);
	va_end(args);
	return (len);
}

