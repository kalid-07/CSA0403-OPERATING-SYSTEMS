#include <stdio.h>
#include <stdlib.h>

void create()
{
    FILE *fp = fopen("sasi.txt","w");
    if(fp) {
        printf("File created successfully");
        fclose(fp);
    }
}

void copy()
{
    FILE *s=fopen("sasi.txt","r");
    FILE *d=fopen("sk.txt","w");
    char c;

    if(!s || !d) return;

    while((c=fgetc(s))!=EOF)
        fputc(c,d);

    fclose(s);
    fclose(d);
    printf("File copied successfully.");
}

int main()
{
    int n;

    printf("1. Create\t2. Copy\t3. Delete\n");
    printf("Enter your choice: ");
    scanf("%d",&n);

    switch(n)
    {
        case 1: create(); break;
        case 2: copy(); break;
        case 3:
            remove("sasi.txt");
            printf("Deleted successfully");
            break;
    }
    return 0;
}
