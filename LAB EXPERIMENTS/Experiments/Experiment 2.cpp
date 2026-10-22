#include <stdio.h>

int main()
{
    FILE *fptr1, *fptr2;
    char source[100], destination[100];
    int c;

    printf("Enter the source filename: ");
    scanf("%99s", source);

    fptr1 = fopen(source, "r");

    if (fptr1 == NULL)
    {
        perror("Error opening source file");
        return 1;
    }

    printf("Enter the destination filename: ");
    scanf("%99s", destination);

    fptr2 = fopen(destination, "w");

    if (fptr2 == NULL)
    {
        perror("Error opening destination file");
        fclose(fptr1);
        return 1;
    }

    while ((c = fgetc(fptr1)) != EOF)
    {
        fputc(c, fptr2);
    }

    printf("Contents copied successfully.\n");

    fclose(fptr1);
    fclose(fptr2);

    return 0;
}
