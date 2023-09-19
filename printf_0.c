#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * _printf - custom like  printf function
 *@format - a string containing format specifiers.
 *main - main entry point of the program's control flow
 */

int _printf(const char *format, ...);
{
	va_list args;

	va_start(args, format)

	int count = 0;

	while (*format)
		if (*format == '%')
		{
			format++;
		if (*format == 'd')
		{
			int num = va_arg(args, int);

			printf("%d", num);
			count++;
		}
		else if (*format == 's')
		{
			char *str = va_arg(args, char*);

			printf("%s", str);
			count += strlen(str);
		}
		else if (*format == 'c')
		{
			char c = va_arg(args, int);

			putchar(c);
			count++;
		}
		else if (*format == '%')
		{
			putchar('%');
			count++;
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
		va_end(args);
		return (count);
		}
int main(void)
{
	int num = 42;
	char str[] = "Hello, World!";
	char c = 'A';

int char_count = _printf("This is a number: %d\n", num);
char_count += _printf("This is a string:%s\n", str);
char_count += _printf("This is a character:%c\n", c);
char_count += _printf("This is a percent sign:%%\n");
printf("Total characters printed:%d\n", char_count);
return (0);
}
