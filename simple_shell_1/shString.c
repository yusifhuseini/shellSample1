#include "shell.h"

/**
 * strLen - string length
 * @s: check string length
 * Code by - Huseini Yusif & Bennet Aboagye-Asare
 * Return: int str length
 */
int strLen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * stringCmp - compare two strings
 * @s1: string 1
 * @s2: string 2
 * Return: neg (s1 < s2), pos (s1 > s2), zero (s1 == s2)
 */
int stringCmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * startsWith - haystack checker
 * @haystack: search string
 * @needle: find substring
 * Return: haystack address or NULL
 */
char *startsWith(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * stringCat - concatenates two strings
 * @dest: buffer destination
 * @src: buffer source
 * Return: buffer dest pointer
 */
char *stringCat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}


/**
 * stringCpy - copy string
 * @dest: destination
 * @src: source
 * Code by - Huseini Yusif & Bennet Aboagye-Asare
 * Return: dest pointer
 */
char *stringCpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/**
 * stringDup - duplicate string
 * @str: duplicate str
 * Return: string dup pointer
 */
char *stringDup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}

/**
 *_puts - print input str
 *@str: print string
 * Return: void
 */
void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		putChar(str[i]);
		i++;
	}
}

/**
 * putChar - writes STDOUT char c
 * @c: print character
 * Return: 1 (success) or -1 (error)
 */
int putChar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
