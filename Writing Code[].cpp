#include <stdio.h>
int n,m,b,mod,a[501];
long long dp[501][501];
int main()
{
	int i,j,k;
	long long ans=0;
	scanf("%d%d%d%d",&n,&m,&b,&mod);
	for (i=1;i<=n;i++)
		scanf("%d",a+i);
	dp[0][0]=1;
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			for (k=a[i];k<=b;k++)
				(dp[j][k]+=dp[j-1][k-a[i]])%=mod;
	for (i=0;i<=b;i++)
		ans+=dp[m][i];
	printf("%I64d",ans%mod);
	return 0;
}
