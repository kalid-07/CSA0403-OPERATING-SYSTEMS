#include <stdio.h>

struct process
{
    char name;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int priority;
};

int main()
{
    int n, i, j;
    int total_wt = 0, total_tat = 0;
    struct process p[20], temp;

    printf("Enter the total number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        p[i].name = 'A' + i;

        printf("\nEnter details of Process %c\n", p[i].name);

        printf("Enter burst time: ");
        scanf("%d", &p[i].burst_time);

        printf("Enter priority: ");
        scanf("%d", &p[i].priority);
    }

    /* Sort according to priority */
    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(p[j].priority > p[i].priority)
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    p[0].waiting_time = 0;

    for(i = 1; i < n; i++)
    {
        p[i].waiting_time = 0;

        for(j = 0; j < i; j++)
        {
            p[i].waiting_time += p[j].burst_time;
        }

        total_wt += p[i].waiting_time;
    }

    printf("\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");

    for(i = 0; i < n; i++)
    {
        p[i].turnaround_time =
            p[i].burst_time + p[i].waiting_time;

        total_tat += p[i].turnaround_time;

        printf("%c\t%d\t\t%d\t\t%d\t\t%d\n",
               p[i].name,
               p[i].burst_time,
               p[i].priority,
               p[i].waiting_time,
               p[i].turnaround_time);
    }

    printf("\nAverage Waiting Time = %.2f",
           (float)total_wt / n);

    printf("\nAverage Turnaround Time = %.2f\n",
           (float)total_tat / n);

    return 0;
}
