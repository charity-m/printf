#include "main.h"
/**
 * prnt_frmt -prints a format specifier
 * @format: format specifier to be printed
 * @args: contains a list of variadic arguments
 * Return: length of format
 */
int prnt_frmt(const char *format, va_list args)
{
	int count = 0;
	int l = 0;

	while (format && format[l])
	{
		if (format[l] == '%')
		{
			if (format[l + 1] == '\0')
				return (-1);
			l++;

			while (format[l] == ' ')
				l++;
			if (format[l] == '%')
				count += ptcha(format[l]);
			if (valid_char(format[l]) == 0)
			{
				count = prnt_invalid(format[l - 1], format[l], count);
			}
			else
			{
				count += prnt_spec(format[l], args);
			}
		}
		else
		{
			count += ptcha(format[l]);
		}
			l++;
	}
	return (count);
}
/**
 * prnt_spec - print a valid specifier
 * @format: the specifier being printed
 * @args: list of variadic arguments
 * Return: length of specifier
 */
int prnt_spec(char format, va_list args)
{
	int l = 0, len = 0;
	spc_dt _types[] = {
		{"c", prnt_char},
		{"s", prnt_strng},
		{"d", prnt_integ},
		{"i", prnt_integ},
		{"b", prnt_int_binary},
		{NULL, NULL}
	};

	while (_types[l].specifier)
	{
		if (*_types[l].specifier == format)
		len = _types[l].v(args);
		l++;
	}
	return (len);
}
/**
 * prnt_invalid -prints an invalid specifier
 * @prev_format: previous specifier of actual specifier
 * @format: the specifier to prints
 * @count: the current count before prints invalid specifier
 * Return: the current count after prints invalid specifiers
 */
int prnt_invalid(char prev_format, char format, int count)
{
	count += ptcha('%');

	if (prev_format == ' ')
	{
		count += ptcha(' ');
		count += ptcha(format);
	}
	else
	{
		count += ptcha(format);
	}
	return (count);
}
/**
 * valid_char -validate the type
 * @_type: character to be comparate
 * Return: 1 if char is equal to a type
 */
int valid_char(char _type)
{
	char _types[] = {'c', 's', 'd', 'i', 'b', '%'};
	int l = 0;

	while (_types[l])
	{
		if (_types[l] == _type)
		return (1);
		l++;
	}
	return (0);
}
