#include <unistd.h>
/**
 * ptcha -prints a character
 * @c: character input
 * Return: 1
 */
int ptcha(char c)
{
	return(write(1, &c, 1));
}
