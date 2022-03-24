#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "regex.h"

/**
 * regex_match - checks whether a given pattern
 * matches a given string
 * @str: String to compare
 * @pattern: Pattern to be compared
 * Return: 1 in match, 0 otherwise
 */
int regex_match(char const *str, char const *pattern)
{
	int matches, i, j;
	matches = 1;
	i = j = 0;

	if (!str || !pattern)
		return (0);

	while (str[i] != '\0' && pattern[j] != '\0' && matches != 0)
	{
		if (strlen(str) != strlen(pattern))
		{
			if (strchr(pattern, '*') == NULL && strchr(pattern, '.') == NULL)
				matches = 0;
		}
		else if (str[i] == pattern[j])
		{
			matches = 1;
		}
		else if (pattern[j] == '*' || pattern[j] == '.')
		{
			return (matches);
		}
		else
			matches = 0;
		i++;
		j++;
	}
	return (matches);
}
