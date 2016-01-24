#include <stdio.h>
int a[1000022];
int main()
{
    int n,x;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        a[x]++;
    }
    for (int i=0;i<=1000020;i++)
    {
        a[i+1]+=a[i]>>1;
        a[i]&=1;
    }
    int ans=0;
    for (int i=0;i<=1000021;i++)
        ans+=a[i];
    printf("%d",ans);
    return 0;
}
