#include "palindrome.h"

/**
 * is_palindrome - Checks if an unsigned long integer is a palindrome
 * @n: The number to check
 *
 * Return: 1 if n is a palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long rev = 0, tmp = n;

	while (tmp > 0)
	{
		rev = rev * 10 + (tmp % 10);
		tmp /= 10;
	}
	return (n == rev);
}
