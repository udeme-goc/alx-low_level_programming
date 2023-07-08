#include <stdlib.h>
#include <time.h>
/**
 * main - function returns positive or negative for integer passed to it
 * code completed by Udeme Harrison
 * Return: 0
 */

int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;

	if (n < 0)
		printf("%d is negative\n", n);
	else
		printf("%d is positive\n", n);

	return (0);
}
