#include <stdio.h>
int n;
int fast_pow(int a,int b)
{
    if (b==0)
        return 1;
    if (b==1)
        return a;
    long long tmp=(long long)fast_pow(a,b>>1);
    tmp%=n;
    tmp*=tmp;
    tmp%=n;
    if (b&1)
        tmp*=a;
    tmp%=n;
    return tmp;
}
int main()
{
    int m,x,k;
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    scanf("%d%d%d%d",&n,&m,&k,&x);
    long long tmp=(long long)fast_pow(10,k);
    tmp*=m;
    tmp%=n;
    tmp+=x;
    tmp%=n;
    printf("%lld",tmp);
    return 0;
}
