#include <stdio.h>
#include <stdlib.h>

void sort(int a[], int n)
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int request[50];
    int n, head, disk_size;
    int i, totalMovement = 0;

    printf("Enter disk size: ");
    scanf("%d", &disk_size);

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request queue:\n");

    for (i = 0; i < n; i++)
        scanf("%d", &request[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    sort(request, n);

    printf("\nC-SCAN Disk Scheduling\n");
    printf("Order: %d", head);

    /* Move towards higher cylinder numbers */
    for (i = 0; i < n; i++)
    {
        if (request[i] >= head)
        {
            totalMovement += abs(head - request[i]);
            head = request[i];
            printf(" -> %d", request[i]);
        }
    }

    /* Move to end */
    totalMovement += abs(head - (disk_size - 1));
    head = disk_size - 1;
    printf(" -> %d", head);

    /* Jump to beginning */
    totalMovement += disk_size - 1;
    head = 0;
    printf(" -> %d", head);

    /* Continue from beginning */
    for (i = 0; i < n; i++)
    {
        if (request[i] < head)
        {
            totalMovement += abs(head - request[i]);
            head = request[i];
            printf(" -> %d", request[i]);
        }
    }

    printf("\n\nTotal Head Movement = %d cylinders\n", totalMovement);

    return 0;
}
