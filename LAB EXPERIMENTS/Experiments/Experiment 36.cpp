#include <stdio.h>

int main()
{
    int n, i;
    int blocks[50];

    printf("Enter number of blocks in the file: ");
    scanf("%d", &n);

    printf("Enter the block numbers:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &blocks[i]);
    }

    printf("\nLinked File Allocation\n");

    printf("Start Block: %d\n", blocks[0]);
    printf("End Block: %d\n", blocks[n - 1]);

    printf("\nLinked List:\n");

    for (i = 0; i < n - 1; i++)
    {
        printf("%d -> ", blocks[i]);
    }

    printf("%d -> NULL\n", blocks[n - 1]);

    return 0;
}
