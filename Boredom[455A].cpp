#include <stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
int sm[100001];
long long dp[100001];
int main()
{
	int n,i,x,l=0;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%d",&x);
		sm[x]++;
		l=max(l,x);
	}
	dp[0]=0;
	dp[1]=sm[1];
	for (i=2;i<=l;i++)
		dp[i]=max(dp[i-1],dp[i-2]+(long long)sm[i]*i);
	printf("%I64d",dp[l]);
	return 0;
}
