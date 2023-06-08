#include "main.h"

/**
 * _strlen - Calculates the length of a string.
 * @s: The string to calculate the length of.
 *
 * Return: The length of the string.
 */

int _strlen(char *s)
{
    if (*s == '\0') /* Base case: end of string */
    {
        return 0;
    }

    return 1 + _strlen(s + 1); /* Call function recursively with next character */
}


/**
 * is_palindrome_recursive - Helper function to check if a string is a palindrome recursively.
 * @s: The string to check.
 * @start: The starting index of the string.
 * @end: The ending index of the string.
 *
 * Return: 1 if the string is a palindrome, 0 otherwise.
 */
int is_palindrome_recursive(char *s, int start, int end)
{
    if (start >= end) /* Base case: reached middle of string or beyond */
    {
        return 1;
    }

    if (s[start] != s[end]) /* If characters at start and end indices are not equal, it's not a palindrome */
    {
        return 0;
    }

    return is_palindrome_recursive(s, start + 1, end - 1); /* Call function recursively with updated indices */
}


/**
 * is_palindrome - Checks if a string is a palindrome.
 * @s: The string to check.
 *
 * Return: 1 if the string is a palindrome, 0 otherwise.
 */

int is_palindrome(char *s)
{
    int len = _strlen(s);

    if (len <= 1) /* Check for empty string or single character string (both are palindromes) */
    {
        return 1;
    }

    return is_palindrome_recursive(s, 0, len - 1); /* Start the recursive palindrome check with start and end indices */
}
