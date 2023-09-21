#include <stdarg.h>
#include <stdio.h>
#define BUFFER_SIZE 1024

int _printf(const char *format, ...);
{
	int print_buff(char buff[], int *buffer_index);
	int print_int(int value);
	va_list args;
	int count = 0;
	int print = 0;
	int buffer_index = 0;
	char buff[BUFFER_SIZE];

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			buff[buffer_index] = '%';
			if (buffer_index == BUFFER_SIZE)
			{
				print_buff(buff, &buffer_index);
				count += buffer_index;
			}
		}
		else if (*format == 'c')
		{
			int ch = va_arg(args, int);

			buff[buffer_index++] = ch;
			if (buffer_index == BUFFER_SIZE)
			{
				print_buff(buff, &buffer_index);
				count += buffer_index;
			}
		}
		else if (*format == 's')
		{
			char *str = va_arg(args, char*);

			while (*str)
			{
				buff[buffer_index++] = *str;
				str++;
				if (buffer_index == BUFFER_SIZE)
				{
					print_buff(buff, &buffer_index);
					count += buffer_index;
				}
			}
		}
		else if (*format == 'd' || *format == 'i')
		{
			int value = va_args(args, int);

			print = print_int(value);
			count += print;
		}
		else
		{
			buff[buffer_index++] = *format;
			if (buffer_index == BUFFER_SIZE)
			{
				print_buff(buff, &buffer_index);
				count += buffer_index;
				format++;
			}
		}
		print_buff(buff, &buffer_index);
		count += buffer_index;

		va_end(args);
		return (count);
	}

