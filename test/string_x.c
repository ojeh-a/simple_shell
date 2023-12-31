#include "shell.h"

/**
 * _strlen - calculate length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(const char *s)
{
	int x = 0;

	if (!s)
		return (0);

	while (*s++)
		x++;
	return (x);
}

/**
 * _strcmp - Compare two strings.
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 * Return: 0 if @s1 and @s2 are equal,
 *         a negative value if @s1 is less than @s2,
 *         or a positive value if @s1 is greater than @s2.
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	return ((int) (*s1) - (*s2));
}

/**
 * _strncmp - Compare two strings up to a specified length.
 * @s1: First string.
 * @s2: Second string.
 * @n: Maximum number of characters to compare.
 *
 * Return: 0 if the strings are equal up to n characters, negative value
 *         if s1 is less than s2, or positive value if s1 is greater than s2.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char x1, x2;

	while (n-- > 0)
	{
		x1 = (unsigned char) *s1++;
		x2 = (unsigned char) *s2++;

		if (x1 != x2)
			return (x1 - x2);
		if (x1 == '\0')
			break;
	}

	return (0);
}

/**
 * _strstr - checks if needle starts with haystack
 * @haystack: string to search
 * @needle: the substring to find
 *
 * Return: address of next char of haystack or NULL
 */
char *_strstr(char *haystack, char *needle)
{
	int x, y;

	for (x = 0; haystack[x] != '\0'; x++)
	{
		if (haystack[x] == needle[0])
		{

			for (y = 0; needle[y] != '\0'; y++)
			{
				if (haystack[x + y] != needle[y])
				{
					break;
				}
			}

			if (needle[y] == '\0')
			{
				return (&haystack[x]);
			}
		}
	}
	return (NULL);
}

/**
 * _strchr - a function that locates a character in a string
 *
 * @s: pointer to our string array input
 * @c: character to locate from input array
 *
 * Return: first occurence of charatcer or null if not found
*/

char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (s);
		s++;
	}
	/**
	 * if c is '\0', you should return
	 * the pointer to the '\0' of the
	 * string s
	*/
	if (*s == c)
		return (s);
	/*return null if not found*/
	return (NULL);
}
