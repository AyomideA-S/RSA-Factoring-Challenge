#include <stdio.h>
#include <stdlib.h>

/**
 * isprime - Function to determine if a number is prime or not.
 * @x: Integer to be checked
 * 
 * Return: 1 if x is prime else 0
 */
int isprime(unsigned long long int x)
{
	if (x == 2 || x == 3)
		return (1);
	if (x <= 1 || x % 2 == 0 || x % 3 == 0)
		return (0);
	for (unsigned long long int i = 5; i * i <= x; i += 6)
	{
		if (x % i == 0 || x % (i + 2) == 0)
			return (0);
	}
	return (1);
}

/**
 * main - Entry point
 * @argc: Argument Count
 * @argv: Argument Vector
 *
 * Return: 0 (Success)
 */
int main(int argc, char *argv[])
{
	FILE *rsa = NULL;
	unsigned long long int *n = malloc(sizeof(unsigned long long int));
	unsigned long long int p, q;

	if (argc > 0)
	{
		rsa = fopen(argv[1], "r");
		if (!rsa)
		{
			perror("fopen");
			printf("Specified file: %s could not be found!", argv[1]);
			return (1);
		}
		while ((fscanf(rsa, "%llu[^\n] ", n) != EOF))
		{
			for (unsigned long long int i = 2; i < (*n / 2) + 1; i++)
			{
				if (*n % i == 0)
				{
					p = *n / i;
					q = i;
					if (isprime(p) && isprime(q))
					{
						printf("%llu=%llu*%llu\n", *n, p, q);
						break;
					}
				}
			}
		}
		fclose(rsa);
		return (0);
	}
}
