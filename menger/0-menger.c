#include <stdio.h>
#include "menger.h"

/**
 * ipow - Integer power: computes base^exp for small non-negative exp.
 * @base: the base (>= 1).
 * @exp:  exponent (>= 0).
 *
 * Return: base raised to exp.
 */
static size_t ipow(size_t base, int exp)
{
	size_t result = 1;
	int i;

	for (i = 0; i < exp; i++)
		result *= base;

	return (result);
}

/**
 * cell_is_filled - Tells if the (row, col) cell is filled for Menger 2D.
 * @row: row index.
 * @col: column index.
 *
 * Return: 1 if filled ('#'), 0 if empty (' ').
 */
static int cell_is_filled(size_t row, size_t col)
{
	while (row > 0 || col > 0)
	{
		if ((row % 3 == 1) && (col % 3 == 1))
			return (0);

		row /= 3;
		col /= 3;
	}

	return (1);
}

/**
 * menger - Draws a 2D Menger Sponge of a given level.
 * @level: level of the sponge (>= 0); if < 0, do nothing.
 *
 * A level N sponge has size 3^N. Level 0 is a single '#'.
 */
void menger(int level)
{
	size_t size, r, c;

	if (level < 0)
		return;

	size = ipow(3, level);

	for (r = 0; r < size; r++)
	{
		for (c = 0; c < size; c++)
		{
			if (cell_is_filled(r, c))
				putchar('#');
			else
				putchar(' ');
		}
		putchar('\n');
	}
}
