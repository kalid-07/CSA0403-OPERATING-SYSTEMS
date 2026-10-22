#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int buffer[SIZE];
int in = 0, out = 0;
int count = 0;

void producer()
{
    int item;

    if (count == SIZE)
    {
        printf("Buffer is full!\n");
        return;
    }

    printf("Enter item to produce: ");
    scanf("%d", &item);

    buffer[in] = item;
    in = (in + 1) % SIZE;
    count++;

    printf("Producer produces item %d\n", item);
}

void consumer()
{
    int item;

    if (count == 0)
    {
        printf("Buffer is empty!\n");
        return;
    }

    item = buffer[out];
    out = (out + 1) % SIZE;
    count--;

    printf("Consumer consumes item %d\n", item);
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n1. Producer");
        printf("\n2. Consumer");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                producer();
                break;

            case 2:
                consumer();
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
