#include <stdio.h>
#define max(a,b) (a>b?a:b)
int nm[1001],dp[1001];
int main()
{
	int n,i,j,ans=0;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%d",nm+i);
		dp[i]=1;
	}
	for (i=2;i<=n;i++)
		for (j=1;j<i;j++)
			if (nm[j]<nm[i])
				dp[i]=max(dp[i],dp[j]+1);
	for (i=1;i<=n;i++)
		ans=max(ans,dp[i]);
	printf("%d",ans);
	return 0;
}
