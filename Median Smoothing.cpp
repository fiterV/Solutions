#include <stdio.h>
#define median(a,b,c) ((a)==(c)?(a):(b))
int a[500001][2];
int main()
{
    int n,i,j;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
        scanf("%d",&a[i][0]);
    for (i=1;i<=500;i++)
    {
        a[1][i&1]=a[1][(i&1)^1];
        a[n][i&1]=a[n][(i&1)^1];
        bool f=true;
        for (j=1;j<n;j++)
        {
            a[j][i&1]=median(a[j-1][(i&1)^1],a[j][(i&1)^1],a[j+1][(i&1)^1]);
            if (a[j][i&1]!=a[j][(i&1)^1])
                f=false;
        }
        if (f)
        {
            printf("%d\n",i-1);
            for (j=1;j<=n;j++)
                printf("%d ",a[j][i&1]);
            return 0;
        }
    }
    printf("-1");
    return 0;
}
