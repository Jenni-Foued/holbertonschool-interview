#include "regex.h"

/**
*regex_match - compares 2 strings including thr presence of special character
*@str: first string
*@pattern: second string
*Return: 1 if same, 0 if not
*/
int regex_match(char const *str, char const *pattern)
{
		int cheks1 = 0, checks2 = 0;

	if (!str || !pattern)
		return (0);

	cheks1 = *str && (*str == *pattern || *pattern == '.');
	checks2 = *(pattern + 1) == '*';

	if (!*str && !checks2)
		return (*pattern ? 0 : 1);

	if (cheks1 && checks2)
		return (regex_match(str + 1, pattern) || regex_match(str, pattern + 2));
	else if (cheks1 && !checks2)
		return (regex_match(str + 1, pattern + 1));
	else if (checks2)
		return (regex_match(str, pattern + 2));

	return (0);
}
