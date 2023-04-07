#include <stdio.h>
#include <string.h>

int count_points(char *cards)
{
	int total;
	int index;

	total = 0;
	index = 0;
	while (cards[index])
	{
		if (cards[index] >= '2' && cards[index] <= '9')
		{
			total += cards[index] - '0';
		}
		else if (strchr("TJDKA", cards[index]))
		{
			if (cards[index] == 'A')
			{
				if (total <= 10)
				{
					total += 11;
				}
				else
				{
					total += 1;
				}
			}
		}
		else
		{
			total += 10;
		}
		index++;
	}
	return total;
}

int main(int argc, char **argv)
{
	int total;

	if (argc != 2 || !argv[1][0])
	{
		printf("Error: Number of agumentos invalido.\n");
		return (1);
	}

	total = count_points(argv[1]);
	if (total == 21)
	{
		printf("Blackjack!\n");
	}
	else
	{
		printf("%d\n", total);
	}
	return (0);
}
