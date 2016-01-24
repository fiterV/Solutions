#include <stdio.h>
int a[500001];
bool stable[500001];
int main()
{
    int n,ans=0;
    scanf("%d%d",&n,a+1);
    stable[1]=stable[n]=true;
    for (int i=2;i<=n;i++)
    {
        scanf("%d",a+i);
        if (a[i]==a[i-1])
            stable[i]=stable[i-1]=true;
    }
    for (int i=1;i<=n;i++)
        if (!stable[i])
        {
            int idx;
            for (idx=i+1;!stable[idx];idx++);
            int length=(idx-i+1)/2;
            if (length>ans)
                ans=length;
            for (int j=i;j<i+length;j++)
                a[j]=a[i-1];
            for (int j=i+length;j<idx;j++)
                a[j]=a[idx];
            i=idx;
        }
    printf("%d\n",ans);
    for (int i=1;i<=n;i++)
        printf("%d ",a[i]);
    return 0;
}
