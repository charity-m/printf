#include "main.h"
/**
 * _printf - custom like printf function
 * @format: a string containing format specifiers
 * Return: number of bytes
 */
int _printf(const char *format, ...)
{
	unsigned int i, str_length, length = 0;
	va_list args;

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ')
		return (-1);

	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (*format == '%' && *(format + 1) != '\0')
		{

