#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *thread_function(void *arg)
{
    printf("Thread is created and running.\n");

    pthread_exit(NULL);
}

int main()
{
    pthread_t t1, t2;

    pthread_create(&t1, NULL, thread_function, NULL);

    printf("Thread created successfully.\n");

    if (pthread_equal(t1, pthread_self()))
        printf("Threads are equal.\n");
    else
        printf("Threads are not equal.\n");

    pthread_join(t1, NULL);

    printf("Thread joined successfully.\n");

    pthread_create(&t2, NULL, thread_function, NULL);
    pthread_join(t2, NULL);

    printf("Second thread completed.\n");

    return 0;
}
