#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * main - count the number of words in a string
 * 
 * Return: 0
 */

int main(void)
{
	FILE *file;
	char i;
	int in_word = 0;
	int word_count = 0;

	file = fopen("datafile.txt", "r");
	if (file == NULL)
	{
		printf("Error opening file\n");
		exit(1);
	}

	while ((i = fgetc(file)) != EOF)
	{
		if (isalpha(i))
		{
			if (in_word)
			{
				in_word = 0;
				word_count++;
			}
		}
		else
		{
			in_word = 1;
		}
	}
	
	if (in_word)
	{
		word_count++;
	}

	fclose(file);
	printf("Word count: %d\n", word_count);

	return (0);
}
