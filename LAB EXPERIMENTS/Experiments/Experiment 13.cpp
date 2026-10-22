#include<stdio.h>

void bestfit(int m[],int p[],int n,int k)
{
    int i,j=0,t;
    for(i=0;i<n&&j<k;i++)
        if(m[i]>=p[j])
        {
            printf("\n%d fits in %d",p[j],m[i]);
            m[i]-=p[j++];
            i--;
        }
    for(;j<k;j++)
        printf("\n%d must wait for its process",p[j]);
}

void sort(int a[],int n,int r)
{
    int i,j,t;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(r ? a[i]>a[j] : a[i]<a[j])
            {
                t=a[i]; a[i]=a[j]; a[j]=t;
            }
}

int main()
{
    int m[20],p[20],n,k,ch,i;

    printf("Number of memory partition : ");
    scanf("%d",&n);
    printf("Number of process : ");
    scanf("%d",&k);

    printf("Enter memory partitions:\n");
    for(i=0;i<n;i++) scanf("%d",&m[i]);

    printf("Enter process size:\n");
    for(i=0;i<k;i++) scanf("%d",&p[i]);

    printf("1.Firstfit  2.Bestfit  3.Worstfit\n");
    scanf("%d",&ch);

    if(ch==1)
    {
        sort(m,n,0);
        sort(p,k,0);
    }
    else if(ch==3)
    {
        sort(m,n,1);
        sort(p,k,0);
    }

    bestfit(m,p,n,k);
    return 0;
}
