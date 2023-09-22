#include "main.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * prnt_char -prints a charaacter
 * @args: a list of variadic arguments
 * Return: the length of the character
 */
int prnt_char(va_list args)
{
	ptcha(va_arg(args, int));
	return (1);
}
/**
 * prnt_strng -prints a string
 * @args: a list of variadic arguments
 * Return: the length of the string
 */
int prnt_strng(va_list args)
{
	char *arg = va_arg(args, char*);
	int l = 0;

	if (arg != NULL)
	{
		while (arg[l])
		{
			ptcha(arg[l]);
			l++;
		}
		return (l);
	}
	ptcha('(');
	ptcha('n');
	ptcha('u');
	ptcha('l');
	ptcha('l');
	ptcha(')');
	return (6);
}
/**
 * prnt_integ -prints an integer
 * @args: a list of variadic arguments
 * Return: the length of string
 */
int prnt_integ(va_list args)
{
	int count = 1, b = 0;
	unsigned int c = 0;

	c = va_arg(args, int);
	b = c;
	if (b < 0)
	{
		ptcha('-');
		b = b * -1;
		c = b;
		count += 1;
	}
	while (c > 9)
	{
		c = c / 10;
		count++;
	}
	recursion_integ(b);
	return (count);
}
/**
 * recursion_integ -prints an integer
 * @r: integer to print
 * Return: nothing
 */
void recursion_integ(int r)
{
	unsigned int v;

	v = r;
	if (v / 10)
		recursion_integ(v / 10);
	ptcha(v % 10 + '0');
}

