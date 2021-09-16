#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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
	char buffer[10];
	int lenBuffer;
	int i = 0;

	if (n / 10 == 0)
		return (1);

	itoa(n, buffer, 10);
	lenBuffer = strlen(buffer) - 1;
	
	while(i < lenBuffer)
	{
		if(buffer[i] != buffer[lenBuffer])
			return (0);
		i++;
		lenBuffer--;
	}
	return (1);
}
