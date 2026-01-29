#include <stdlib.h>
#include <string.h>
#include "substring.h"

/**
* match_words - checks if substring at position matches all words
* @s: the string to check
* @words: array of words to match
* @nb_words: number of words
* @word_len: length of each word
*
* Return: 1 if all words match exactly once, 0 otherwise
*/
static int match_words(char const *s, char const **words,
			int nb_words, int word_len)
{
	int *used;
	int i, j, found;

	used = calloc(nb_words, sizeof(int));
	if (!used)
		return (0);

	for (i = 0; i < nb_words; i++)
	{
		found = 0;
		for (j = 0; j < nb_words; j++)
		{
			if (!used[j] && strncmp(s + i * word_len,
						words[j], word_len) == 0)
			{
				used[j] = 1;
				found = 1;
				break;
			}
		}
		if (!found)
		{
			free(used);
			return (0);
		}
	}
	free(used);
	return (1);
}

/**
* add_index - adds an index to the result array, resizing if needed
* @result: pointer to result array
* @count: pointer to current count
* @capacity: pointer to current capacity
* @index: index to add
*
* Return: 1 on success, 0 on failure
*/
static int add_index(int **result, int *count, int *capacity, int index)
{
	int *temp;

	if (*count >= *capacity)
	{
		*capacity *= 2;
		temp = realloc(*result, *capacity * sizeof(int));
		if (!temp)
			return (0);
		*result = temp;
	}
	(*result)[(*count)++] = index;
	return (1);
}

/**
* find_substring - finds all substrings containing concatenation of words
* @s: the string to scan
* @words: array of words to find
* @nb_words: number of words in array
* @n: pointer to store number of indices found
*
* Return: allocated array of indices, or NULL if none found
*/
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int *result, s_len, word_len, total_len, i, count = 0, capacity = 10;

	*n = 0;
	if (!s || !words || nb_words <= 0 || !words[0])
		return (NULL);
	s_len = strlen(s);
	word_len = strlen(words[0]);
	total_len = word_len * nb_words;
	if (s_len < total_len || word_len == 0)
		return (NULL);
	result = malloc(capacity * sizeof(int));
	if (!result)
		return (NULL);
	for (i = 0; i <= s_len - total_len; i++)
	{
		if (match_words(s + i, words, nb_words, word_len))
			if (!add_index(&result, &count, &capacity, i))
			{
				free(result);
				return (NULL);
			}
	}
	if (count == 0)
	{
		free(result);
		return (NULL);
	}
	*n = count;
	return (result);
}
