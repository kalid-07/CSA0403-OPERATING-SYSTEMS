#include <stdio.h>
#include <pthread.h>

int shared = 0;
pthread_mutex_t mutex;

void *update(void *arg)
{
    int id = *(int *)arg;

    pthread_mutex_lock(&mutex);
    shared += 5;
    printf("Thread %d updated the variable\n", id);
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main()
{
    pthread_t t[3];
    int id[3] = {1, 2, 3};

    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < 3; i++)
        pthread_create(&t[i], NULL, update, &id[i]);

    for (int i = 0; i < 3; i++)
        pthread_join(t[i], NULL);

    printf("\nFinal value: %d\n", shared);

    pthread_mutex_destroy(&mutex);
    return 0;
}
