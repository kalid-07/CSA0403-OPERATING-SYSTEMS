#include <stdio.h>

int main()
{
    int indexBlock, n, i;
    int blocks[50];

    printf("Enter index block: ");
    scanf("%d", &indexBlock);

    printf("Enter number of blocks required: ");
    scanf("%d", &n);

    printf("Enter the block numbers:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &blocks[i]);
    }

    printf("\nIndexed File Allocation\n");
    printf("Index Block: %d\n", indexBlock);

    printf("File blocks:\n");

    for (i = 0; i < n; i++)
    {
        printf("Index[%d] -> Block %d\n", i, blocks[i]);
    }

    return 0;
}
