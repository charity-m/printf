#include "main.h"
/**
 * prnt_int_binary -prints an int converted to a binary
 * @args: list of variadic arguments
 * Return: number of printed digits
 */
int prnt_int_binary(va_list args)
{
	unsigned int y = 0;
	int c = 0, new = 0;

	new = va_arg(args, int);

	y = new;

	if (new < 0)
	{
		ptcha('1');
		new = new * -1;
		y = new;
		c += 1;
	}
	while (y > 0)
	{
		y = y / 2;
		c++;
	}
	recursion_int_binary(new);
	return (c);
}
/**
 * recursion_int_binary -prints a binary
 * @r: integer to print
 */
void recursion_int_binary(int r)
{
	unsigned int o;

	o = r;
	if (o / 2)
		recursion_int_binary(o / 2);
	ptcha(o % 2 + '0');
}
