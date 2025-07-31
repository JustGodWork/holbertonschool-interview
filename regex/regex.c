#include "regex.h"

/**
 * regex_match - Checks if a pattern matches a string (supports . and *)
 * @str: The string to scan
 * @pattern: The regular expression
 *
 * Return: 1 if pattern matches str, 0 otherwise
 */
int regex_match(char const *str, char const *pattern)
{
	if (!pattern || !str)
		return (0);
	if (*pattern == '\0')
		return (*str == '\0');
	if (*(pattern + 1) == '*')
	{
		if (regex_match(str, pattern + 2))
			return (1);
		if ((*str && (*pattern == *str || *pattern == '.')) &&
			regex_match(str + 1, pattern))
			return (1);
		return (0);
	}
	if (*str && (*pattern == *str || *pattern == '.'))
		return (regex_match(str + 1, pattern + 1));
	return (0);
}
