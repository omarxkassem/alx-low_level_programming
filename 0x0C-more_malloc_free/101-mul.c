#include "holberton.h"

/**
 * _puts - prints a string
 * @str: The string to be printed.
 */
void _puts(char *str)
{
	int counter;

	counter = 0;
	for (counter = 0; *(str + counter) != '\0'; counter++)
		_putchar(*(str + counter));
	_putchar('\n');
}

/**
 * num_of_digits - checks if a string has digits.
 * @str: The string to be checked.
 *
 * Description: checks if a string has digits and returns its length if
 *              it has. Exits the program with exit code 98 otherwise.
 * Return:  counter if all the string has digits, exits program otherwise.
 */
int num_of_digits(char *str)
{
	int counter;

	counter = 0;

	while (str[counter] != '\0')
	{
		if (str[counter] >= '0' && str[counter] <= '9')
			counter++;
		else
		{
			_puts("Error");
			exit(98);
		}
	}

	return (counter);
}

/**
 * _calloc - allocates memory and initializes with '0'.
 * @nmemb: The amount of elements to be allocated.
 * @size: The size of each nmemb element.
 *
 * Return: A pointer to the address if successful at allocating memory.
 *         Otherwise, returns NULL. NULL if nmemb or size is 0.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *p_alloc;
	unsigned int counter;

	p_alloc = NULL;
	counter = 0;

	if (nmemb == 0 || size == 0)
		return (NULL);

	p_alloc = malloc(size * nmemb);
	if (p_alloc == NULL)
	{
		_puts("Error");
		exit(98);
	}

	for (counter = 0; counter < size * nmemb; counter++)
		((char *) p_alloc)[counter] = '0';
	return (p_alloc);
}

/**
 * multiply - multiplies two numbers and prints its product.
 * @p_prod: The array in which it will be stored the result.
 * @n1: The first number.
 * @n2: The second number.
 * @len_n1: The total number of digits of the first number.
 * @len_n2: The total number of digits of the second number.
 */
void multiply(char *p_prod, char *n1, char *n2, int *len_n1, int *len_n2)
{
	int curr, c1, c2, prod, carry_m, sum, carry_s;

	curr = c1 = c2 = prod = carry_m = sum = carry_s = 0;

	for (c1 = *len_n2 - 1; c1 >= 0; c1--)
	{
		for (c2 = *len_n1 - 1; c2 >= 0; c2--)
		{
			curr = c1 + c2 + 1;

			prod = (n2[c1] - '0') * (n1[c2] - '0') + carry_m;
			carry_m = prod / 10;
			if (c2 == 0 && carry_m > 0)
				p_prod[curr - 1] = carry_m + '0';

			sum = (p_prod[curr] - '0') + prod % 10 + carry_s;
			carry_s = sum / 10;
			p_prod[curr] = sum % 10 + '0';
			if (c2 == 0 && carry_s > 0)
				p_prod[curr - 1] += carry_s;
		}
		carry_m = carry_s = 0;
	}

	if (*p_prod == '0')
		_puts(p_prod + 1);
	else
		_puts(p_prod);
	free(p_prod);
}

/**
 * main - main program for multiplying 2 numbers.
 * @argc: The argument count.
 * @argv: The argument vector.
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int len_n1, len_n2;
	char *p_prod;

	len_n1 = len_n2 = 0;
	p_prod = NULL;

	if (argc != 3)
	{
		_puts("Error");
		exit(98);
	}

	if (argv[1][0] == '0' || argv[2][0] == '0')
	{
		_puts("0");
		return (0);
	}

	len_n1 = num_of_digits(argv[1]);
	len_n2 = num_of_digits(argv[2]);

	p_prod = _calloc(len_n1 + len_n2 + 1, sizeof(*p_prod));
	p_prod[len_n1 + len_n2] = '\0';

	multiply(p_prod, argv[1], argv[2], &len_n1, &len_n2);

	return (0);
}
