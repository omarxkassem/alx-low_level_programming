#include "holberton.h"

/**
 * main - prints program's arguments including the first one.
 * @argc: Program's argument count.
 * @argv: Program's argument vector.
 *
 * Return: Always 0 (success).
 */
int main(int argc, char *argv[])
{
	int index;

	index = 0;
	for (index = 0; index < argc; index++)
		printf("%s\n", argv[index]);

	return (0);
}
