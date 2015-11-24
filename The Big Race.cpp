#include <stdio.h>
long long gcd(long long a,long long b)
{
    return b>0?gcd(b,a%b):a;
}
int main()
{
    long long n,v,w,ans,l;
	scanf("%I64d%I64d%I64d",&n,&v,&w);
	if(v>w)
	{
	    long long tmp=v;
	    v=w;
	    w=tmp;
	}
	l=(long double)v/gcd(v,w)*w>(long double)n?n+1:v/gcd(v,w)*w;
	ans=n/l*v+(v-1>n%l?n%l:v-1);
	printf("%I64d/%I64d",ans/gcd(ans,n),n/gcd(ans,n));
	return 0;
}
