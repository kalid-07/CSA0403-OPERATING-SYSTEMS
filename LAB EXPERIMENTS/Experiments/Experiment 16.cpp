#include <stdio.h>

struct Employee
{
    int id;
    char name[50];
    float salary;
};

int main()
{
    FILE *fp;
    struct Employee e;
    int ch;

    fp=fopen("employee.dat","rb+");
    if(fp==NULL) fp=fopen("employee.dat","wb+");

    do
    {
        printf("\n1.Add Employee\n2.Display Employee\n3.Update Employee\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&ch);

        if(ch==1)
        {
            printf("Enter ID Name Salary: ");
            scanf("%d %s %f",&e.id,e.name,&e.salary);
            fseek(fp,(e.id-1)*sizeof(e),SEEK_SET);
            fwrite(&e,sizeof(e),1,fp);
            printf("Employee added successfully.\n");
        }
        else if(ch==2)
        {
            printf("Enter Employee ID: ");
            scanf("%d",&e.id);
            fseek(fp,(e.id-1)*sizeof(e),SEEK_SET);
            fread(&e,sizeof(e),1,fp);
            printf("ID: %d\nName: %s\nSalary: %.2f\n",
                   e.id,e.name,e.salary);
        }
        else if(ch==3)
        {
            printf("Enter Employee ID: ");
            scanf("%d",&e.id);
            fseek(fp,(e.id-1)*sizeof(e),SEEK_SET);
            fread(&e,sizeof(e),1,fp);

            printf("Enter new Name and Salary: ");
            scanf("%s %f",e.name,&e.salary);

            fseek(fp,(e.id-1)*sizeof(e),SEEK_SET);
            fwrite(&e,sizeof(e),1,fp);
            printf("Employee updated successfully.\n");
        }
    }while(ch!=4);

    fclose(fp);
    return 0;
}
