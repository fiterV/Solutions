#include <stdio.h>
#include <algorithm>
#define mod 1000000007
using namespace std;
long long a[200001],b[200001];
int dp[2005];
pair<int,int> pos[2005];
long long ksm(long long x,int y)
{
	if (!y)
		return 1;
	x%=mod;
	long long tmp=ksm(x,y>>1);
	tmp=tmp*tmp%mod;
	if (y&1)
		tmp=tmp*x%mod;
	return tmp;
}
long long C(int x,int y)
{
	return (((a[x]*b[y])%mod)*b[x-y])%mod;
}
int main()
{
	int w,h,n,i,j;
	a[0]=1;
	b[0]=1;
	for (i=1;i<=200000;i++)
	{
		a[i]=(a[i-1]*i)%mod;
		b[i]=ksm(a[i],mod-2);
	}
	scanf("%d%d%d",&h,&w,&n);
	for (i=1;i<=n;i++)
		scanf("%d%d",&pos[i].first,&pos[i].second);
	sort(pos+1,pos+n+1);
	pos[n+1]=make_pair(h,w);
	for (i=1;i<=n+1;i++)
	{
		int tx=pos[i].first,ty=pos[i].second;
		dp[i]=C(tx+ty-2,ty-1);
		for (j=1;j<i;j++)
			if (pos[j].first<=tx&&pos[j].second<=ty)
				dp[i]=(dp[i]+mod-(dp[j]*C(tx-pos[j].first+ty-pos[j].second,tx-pos[j].first)%mod))%mod;
	}
	printf("%d",dp[n+1]);
	return 0;
}
