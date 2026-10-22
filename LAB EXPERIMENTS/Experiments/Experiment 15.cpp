#include <stdio.h>
#include <direct.h>

int main()
{
    char mainDir[] = ".";
    char subDir[] = "os";
    char fileName[] = "example.txt";
    char path[100];

    _mkdir(subDir);

    sprintf(path, "%s/%s/%s", mainDir, subDir, fileName);

    FILE *file = fopen(path, "w");

    if(file == NULL)
    {
        printf("Error creating file.\n");
        return 1;
    }

    fprintf(file, "This is an example file content.");
    fclose(file);

    printf("File created successfully: %s\n", path);

    return 0;
}
