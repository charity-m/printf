#include "main.h"
/**
 * putss -prints a string
 * @c: string
 * Return: number of bytes
 */
int putss(char *c)
{
	int count = 0;
	
	if (c)
	{
		for (count = 0; c[count] != '\0'; count++)
		{
			ptcha(c[count]);
		}
	}
	return (count);
}
