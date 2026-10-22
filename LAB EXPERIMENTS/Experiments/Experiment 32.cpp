#include <stdio.h>

int main()
{
    int pages[50], frames[10], recent[10];
    int n, f, i, j, pos;
    int pageFaults = 0, hit;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for (i = 0; i < f; i++)
    {
        frames[i] = -1;
        recent[i] = -1;
    }

    for (i = 0; i < n; i++)
    {
        hit = 0;

        for (j = 0; j < f; j++)
        {
            if (frames[j] == pages[i])
            {
                hit = 1;
                recent[j] = i;
                break;
            }
        }

        if (!hit)
        {
            pos = 0;

            for (j = 0; j < f; j++)
            {
                if (frames[j] == -1)
                {
                    pos = j;
                    break;
                }

                if (recent[j] < recent[pos])
                    pos = j;
            }

            frames[pos] = pages[i];
            recent[pos] = i;
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
