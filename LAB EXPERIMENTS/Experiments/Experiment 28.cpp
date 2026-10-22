#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp;
    char filename[50], word[50], line[200];

    printf("Enter file name: ");
    scanf("%s", filename);

    printf("Enter word to search: ");
    scanf("%s", word);

    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("File not found!\n");
        return 1;
    }

    printf("\nLines containing '%s':\n", word);

    while (fgets(line, sizeof(line), fp))
    {
        if (strstr(line, word) != NULL)
        {
            printf("%s", line);
        }
    }

    fclose(fp);

    return 0;
}
