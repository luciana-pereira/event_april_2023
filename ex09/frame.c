#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int get_len(int argc, char *argv[])
{
	int len;
	char *word;
	char *c;
	int index;
	int aux;

	index = 0;
	len = 0;
	aux = 0;
	while (index < argc)
	{
		word = strdup(*(argv + index));
		c = strtok(word, " ");
		while (c)
		{
			aux = strlen(c);
			if (aux > len)
				len = aux;
			c = strtok(0, " ");
		}
		free(word);
		index++;
	}
	return (len);
}

void put_line(int len)
{
	int index;

	index = 0;
	while (index < len)
	{
		printf("*");
		index++;
	}
	printf("\n");
}

char *ft_line(char *word, int len)
{
	char *line;
	char *str;

	line = calloc(len + 1, 1);
	if (!line)
	{
		return (0);
	}
	str = line;
	while (*word)
	{
		*str++ = *word++;
		len--;
	}
	while (len--)
		*str++ = ' ';
	return (line);
}

int main (int argc, char **argv)
{
	char *word;
	char *line;
	int index;
	int len;

	index = 1;
	if (argc < 2)
	{
		return (0);
	}
	len = get_len(argc, argv);
	put_line(len + 4);
	while (index < argc)
	{
		word = strtok(*(argv + index), " ");
		while (word)
		{
			line = ft_line(word, len);
			printf("* %s *\n", line);
			free(line);
			word = strtok(0, " ");
		}
		index++;
	}
	put_line(len + 4);
	return (0);
}
