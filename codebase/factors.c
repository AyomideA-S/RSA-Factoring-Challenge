#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point
 * @argc: Argument Count
 * @argv: Argument Vector
 *
 * Return: 0 (Success)
 */
int main(int argc, char *argv[])
{
	FILE *test = NULL;
	unsigned long long int *n = malloc(sizeof(unsigned long long int));

	if (argc > 0)
	{
		test = fopen(argv[1], "r");
		if (!test)
		{
			perror("fopen");
			return (1);
		}
		while ((fscanf(test, "%llu[^\n] ", n) != EOF))
		{
			for (unsigned long long int i = 2; i < (*n / 2) + 1; i++)
			{
				if (*n % i == 0)
				{
					printf("%llu=%llu*%llu\n", *n, *n / i, i);
					break;
				}
			}
		}
		fclose(test);
		return (0);
	}
}
