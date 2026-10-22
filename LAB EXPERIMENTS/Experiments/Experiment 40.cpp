
#include <stdio.h>

int main()
{
    int p[3][3] = {
        {1, 1, 1},  // Owner: rwx
        {1, 0, 1},  // Group: r-x
        {1, 0, 0}   // Others: r--
    };

    int user, choice;

    printf("Linux File Access Permissions\n");
    printf("1. Owner\n2. Group\n3. Others\n");
    printf("Enter user type: ");
    scanf("%d", &user);

    if (user < 1 || user > 3)
    {
        printf("Invalid user type\n");
        return 0;
    }

    printf("\n1. Read\n2. Write\n3. Execute\n");
    printf("Enter permission: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > 3)
    {
        printf("Invalid permission\n");
        return 0;
    }

    if (p[user - 1][choice - 1])
        printf("Access Granted\n");
    else
        printf("Access Denied\n");

    return 0;
}

