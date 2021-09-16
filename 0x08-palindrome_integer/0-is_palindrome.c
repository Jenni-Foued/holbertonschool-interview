#include "palindrome.h"

/**
 * is_palindrome - checks whether or not a given unsigned integer is a palindrome.
 *
 * @n: the number to be checked.
 *
 * Return: 1 if n is a palindrome, and 0 otherwise.
 */
int is_palindrome(unsigned long n)
{
	unsigned long nReverse = 0;
	unsigned long temp;

	temp = n;
	while (temp != 0)
	{
		nReverse = nReverse * 10 + (temp % 10);
		temp /= 10;
	}

	if (n == nReverse)
		return (1);
	return (0);
}
