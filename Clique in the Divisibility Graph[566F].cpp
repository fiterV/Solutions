#include <stdio.h>
#include <math.h>
#define max(a,b) ((a)>(b)?(a):(b))
int dp[1000001],cnt[1000001];
int main()
{
	int n,i,j,x,ans=0;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%d",&x);
		cnt[x]++;
	}
	for (i=1;i<=1000000;i++)
		if (cnt[i])
		{
			dp[i]=max(dp[i],1);
			for (j=i+i;j<=1000000;j+=i)
				if (cnt[j])
					dp[j]=max(dp[j],dp[i]+1);
		}
	for (i=1;i<=1000000;i++)
		ans=max(ans,dp[i]);
	printf("%d",ans);
	return 0;
}
