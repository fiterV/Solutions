#include <stdio.h>
#include <string.h>
#define max(a,b) (a>b?a:b)
int dp[102][20002],a[102],b[102];
int main()
{
	int n,k,i,j,l;
	scanf("%d%d",&n,&k);
	for (i=1;i<=n;i++)
		scanf("%d",a+i);
	for (i=1;i<=n;i++)
		scanf("%d",b+i);
	for (i=0;i<102;i++)
		for (j=0;j<20002;j++)
			dp[i][j]=-1000000000;
	dp[0][10000]=0;
	for (i=0;i<n;i++)
		for (j=0;j<=20000;j++)
		{
			if (j+a[i+1]-b[i+1]*k<=20000&&j+a[i+1]-b[i+1]*k>=0)
				dp[i+1][j+a[i+1]-b[i+1]*k]=max(dp[i+1][j+a[i+1]-b[i+1]*k],dp[i][j]+a[i+1]);
			dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
		}
	printf("%d",dp[n][10000]>0?dp[n][10000]:-1);
	return 0;
}
