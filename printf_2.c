#include <stdio.h>

void custom_printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%' && *(format + 1) == 'b')
		{
			unsigned int num = va_arg(args, unsigned int);
			int binary[32];
			int i = 0;

			while (num > 0)
			{
				binary[i] = num % 2;
				num /= 2;
				i++;
			}
			for (int j = i - 1; j > = 0; j--)
			{
				ptcha('0' + binary[j]);
			}
			format += 2;
		}
		else
		{
			ptcha(*format);
			format++;
		}
		va_end(args);
		int main(void)
		{
			unsigned int num = 42;

			custom_printf("Binary:%b\n", num);
			printf("Binary:%b\n", num);
			return (0);
		}
