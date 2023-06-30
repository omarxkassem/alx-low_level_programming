#include "holberton.h"

/**
 * *_strncpy - copies a string, printing NUL characters if the size of
 *             destination is large enough, or cropping otherwise.
 * @dest: the destination string.
 * @src: the source string.
 * @n: the size of the destination string.
 *
 * Return: a pointer of the resulting string.
 */
char *_strncpy(char *dest, char *src, int n)
{
	int len_src, counter, null_chars;

	len_src = counter = null_chars = 0;

	while (src[len_src] != '\0')
		len_src++;

	if (n >= 0)
	{
		while (counter < n)
		{
			dest[counter] = src[counter];
			counter++;
		}
		if (n - len_src > 0)
		{
			null_chars = n - len_src;
			counter = 0;
			while (counter < null_chars)
			{
				dest[counter + len_src] = '\0';
				counter++;
			}
		}
	}

	return (dest);
}
