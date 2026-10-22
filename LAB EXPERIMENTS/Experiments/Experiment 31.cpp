#include <stdio.h>

int main()
{
    int pages[50], frames[10];
    int n, f, i, j, k = 0;
    int pageFaults = 0, hit;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for (i = 0; i < f; i++)
        frames[i] = -1;

    for (i = 0; i < n; i++)
    {
        hit = 0;

        for (j = 0; j < f; j++)
        {
            if (frames[j] == pages[i])
            {
                hit = 1;
                break;
            }
        }

        if (!hit)
        {
            frames[k] = pages[i];
            k = (k + 1) % f;
            pageFaults++;
        }

        printf("\nPage %d: ", pages[i]);

        for (j = 0; j < f; j++)
        {
            if (frames[j] == -1)
                printf("- ");
            else
                printf("%d ", frames[j]);
        }

        if (hit)
            printf("Hit");
        else
            printf("Page Fault");
    }

    printf("\n\nTotal Page Faults = %d\n", pageFaults);

    return 0;
}
