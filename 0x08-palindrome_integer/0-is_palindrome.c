#include "palindrome.h"

/**
 * is_palindrome - Check if a given number ispalindrome
 *
 * @n: number to check
 *
 * Return: 1 if palindrome 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long result = 0, reverse = 0, num = 0;

	num = n;
	while (num != 0)
	{
		result = num % 10;
		reverse = reverse * 10 + result;
		num /= 10;
	}

	if (n == reverse)
		return (1);

	return (0);
}
