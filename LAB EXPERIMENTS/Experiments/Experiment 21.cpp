#include <stdio.h>

void worstFit(int blockSize[], int m, int processSize[], int n) {
    // Array to store the block id allocated to each process
    int allocation[n];

    // Initialize all allocations as -1 (unallocated)
    for (int i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    // Pick each process and find the worst fit block
    for (int i = 0; i < n; i++) {
        int worstIdx = -1;

        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (worstIdx == -1) {
                    worstIdx = j;
                } else if (blockSize[j] > blockSize[worstIdx]) {
                    worstIdx = j;
                }
            }
        }

        // If a suitable block was found
        if (worstIdx != -1) {
            // Assign block j to process i
            allocation[i] = worstIdx;

            // Reduce available memory in this block
            blockSize[worstIdx] -= processSize[i];
        }
    }

    // Print allocation results
    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < n; i++) {
        printf(" %d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1) {
            printf("%d\n", allocation[i] + 1);
        } else {
            printf("Not Allocated\n");
        }
    }
}

int main() {
    int m, n;

    printf("Enter number of memory blocks: ");
    scanf("%d", &m);
    int blockSize[m];

    printf("Enter size of each block:\n");
    for (int i = 0; i < m; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &blockSize[i]);
    }

    printf("\nEnter number of processes: ");
    scanf("%d", &n);
    int processSize[n];

    printf("Enter size of each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &processSize[i]);
    }

    worstFit(blockSize, m, processSize, n);

    return 0;
}
