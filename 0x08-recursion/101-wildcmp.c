#include "main.h"

/**
 * wildcmp - Compares two strings and checks if they can be considered identical.
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 *
 * Return: 1 if the strings can be considered identical, 0 otherwise.
 */

int wildcmp(char *s1, char *s2)
{
    if (*s1 == '\0' && *s2 == '\0') /* Base case: both strings are empty */
    {
        return 1;
    }

    if (*s2 == '*') /* If s2 contains '*', it can match any string */
    {
        if (*s1 == '\0' && wildcmp(s1, s2 + 1)) /* Check if remaining s2 is all '*' */
        {
            return 1;
        }

        if (*s1 != '\0' && (wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1))) /* Try skipping a character in s1 or s2 */
        {
            return 1;
        }
    }

    if (*s1 != '\0' && *s2 != '\0' && (*s1 == *s2 || *s2 == '?')) /* If current characters match or s2 contains '?', continue comparing */
    {
        return wildcmp(s1 + 1, s2 + 1);
    }
    return 0; /* If none of the conditions match, the strings are not identical */
}