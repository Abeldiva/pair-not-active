#include <stdlib.h>
#include "shell.h"

/**
 * **strtow - splits a string into words. Repeat delimiters are ignored
 * @str: the input string
 * @d: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **strtow(char *str, char *d)
{
	int a, i, j, l, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (a = 0; str[a] != '\0'; a++)
		if (!is_delim(str[a], d) && (is_delim(str[a + 1], d) || !str[a + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (a = 0, i = 0; i < numwords; i++)
	{
		while (is_delim(str[a], d))
			a++;
		j = 0;
		while (!is_delim(str[a + j], d) && str[a + j])
			j++;
		s[i] = malloc((j + 1) * sizeof(char));
		if (!s[i])
		{
			for (j = 0; j < i; j++)
				free(s[j]);
			free(s);
			return (NULL);
		}
		for (l = 0; l < j; l++)
			s[i][l] = str[a++];
		s[i][l] = 0;
	}
	s[i] = NULL;
	return (s);
}

/**
 * **strtow2 - splits a string into words
 * @str: the input string
 * @d: the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *str, char d)
{
	int a, i, j, l, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (a = 0; str[a] != '\0'; a++)
		if ((str[a] != d && str[a + 1] == d) ||
				    (str[a] != d && !str[a + 1]) || str[a + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (a = 0, i = 0; i < numwords; i++)
	{
		while (str[a] == d && str[a] != d)
			a++;
		j = 0;
		while (str[a + j] != d && str[a + j] && str[a + j] != d)
			j++;
		s[i] = malloc((j + 1) * sizeof(char));
		if (!s[i])
		{
			for (j = 0; j < i; j++)
				free(s[j]);
			free(s);
			return (NULL);
		}
		for (l = 0; l < j; l++)
			s[i][l] = str[a++];
		s[i][l] = 0;
	}
	s[i] = NULL;
	return (s);
}
