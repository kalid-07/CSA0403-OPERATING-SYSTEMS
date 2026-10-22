#include <stdio.h>
#include <windows.h>

DWORD WINAPI thread1(LPVOID arg)
{
    printf("Hello from Thread 1!\n");
    return 0;
}

DWORD WINAPI thread2(LPVOID arg)
{
    printf("Hello from Thread 2!\n");
    return 0;
}

int main()
{
    HANDLE t1, t2;

    t1 = CreateThread(NULL, 0, thread1, NULL, 0, NULL);
    t2 = CreateThread(NULL, 0, thread2, NULL, 0, NULL);

    WaitForSingleObject(t1, INFINITE);
    WaitForSingleObject(t2, INFINITE);

    CloseHandle(t1);
    CloseHandle(t2);

    return 0;
}
