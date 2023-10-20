#include "monty.h"

/**
 * _strtoky - Tokenizes a string based on delimiters.
 * @s: The string to tokenize.
 * @d: The delimiters.
 * Return: The first partition of the string.
 */
char *_strtoky(char *s, char *d)
{
	static char *last_token;
	int i = 0, j = 0;

	if (!s)
		s = last_token;

	while (s[i] != '\0')
	{
		if (_sch(d, s[i]) == 0 && s[i + 1] == '\0')
		{
			last_token = s + i + 1;
			*last_token = '\0';
			s = s + j;
			return (s);
		}
		else if (_sch(d, s[i]) == 0 && _sch(d, s[i + 1]) == 0)
			i++;
		else if (_sch(d, s[i]) == 0 && _sch(d, s[i + 1]) == 1)
		{
			last_token = s + i + 1;
			*last_token = '\0';
			last_token++;
			s = s + j;
			return (s);
		}
		else if (_sch(d, s[i]) == 1)
		{
			j++;
			i++;
		}
	}

	return (NULL);
}

/**
 * _sch - Searches for a character in a string.
 * @s: The string to search in.
 * @c: The character to find.
 * Return: 1 if the character is found, 0 if not.
 */
int _sch(char *s, char c)
{
	int cont = 0;

	while (s[cont] != '\0')
	{
		if (s[cont] == c)
		{
			break;
		}
			cont++;
	}

	return ((s[cont] == c) ? 1 : 0);
}

/**
 * _strcmp - Compares two strings character by character.
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 * Return: 0 if s1 and s2 are equal, 1 if s1 > s2, -1 if s1 < s2.
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] && s1[i]; i++)
		;

	if (s1[i] > s2[i])
		return (1);
	if (s1[i] < s2[i])
		return (-1);
	return (0);
}
