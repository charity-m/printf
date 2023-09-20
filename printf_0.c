#include "main.h"
/**
 * _printf - custom like printf function
 * @format: a string containing format specifiers
 * Return: number of bytes
 */
int _printf(const char *format, ...)
{
	unsigned int i, str_count, count = 0;
	va_list args;

	if (format == NULL)
		return (-1);
	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			ptcha(format[i]);
		}
		else if (format[i + 1] == 'c')
		{
			ptcha(va_arg(args, int));
			i++;
		}
		else if (format[i + 1] == 's')
		{
			str_count = putss(va_arg(args, char*));
			i++;
			count += (str_count - 1);
		}
		else if (format[i + 1] == '%')
		{
			ptcha('%');
		}
		count += 1;
		}
		va_end(args);
		return (count);
}
