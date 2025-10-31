#include <stdio.h>
#include <stdlib.h>

#include "menger.h"

/**
 * main - Entry point.
 *
 * @ac: arguments counter.
 * @av: arguments vector.
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int ac, char **av)
{
	int level;

	if (ac < 2)
	{
		fprintf(stderr, "Usage: %s level\n", av[0]);
		return (EXIT_FAILURE);
	}

	level = atoi(av[1]);
	menger(level);

	return (EXIT_SUCCESS);
}
