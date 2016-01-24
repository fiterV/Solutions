#include <stdio.h>
int main()
{
    int n,x,idx=0;
    bool f=false;
    long long ans=1;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        if (x==1)
        {
            if (idx)
                ans*=i-idx;
            idx=i;
        }
        f=f||x;
    }
    printf("%I64d",f?ans:0);
    return 0;
}
