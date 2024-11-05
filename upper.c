#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * main - Entry point
 *
 * Return: 0
 */
int main(void)
{
    FILE *file;
    char i;
    FILE *output;

    file = fopen("datafile.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    output = fopen("output.txt", "w");
    if (output == NULL)
    {
        printf("Error opening file\n");
        fclose(file);
        exit(1);
    }

    while ((i = fgetc(file)) != EOF)
    {
        fputc(toupper(i), output);
    }

    fclose(file);
    fclose(output);

    if (remove("datafile.txt") != 0)
    {
        printf("Error deleting file\n");
        exit(1);
    }

    if (rename("output.txt", "datafile.txt") != 0)
    {
        printf("Error renaming file\n");
        exit(1);
    }

    return (0);
}
