#include <stdio.h>
#define max(a,b) (a>b?a:b)
int dp[101][101],b[101][101],mx[101][101];
int main()
{
	int f,v,i,j,k,t,tmp=-1000000000;
	scanf("%d%d",&f,&v);
	for (i=1;i<=f;i++)
		for (j=1;j<=v;j++)
			scanf("%d",&b[i][j]);
	for (i=1;i<=v;i++)
		dp[1][i]=tmp=max(tmp,b[1][i]);
	tmp=0;
	for (i=1;i<=f;i++)
		dp[i][i]=tmp+=b[i][i];
	for (i=2;i<=f;i++)
		for (j=i+1;j<=v;j++)
		{
			dp[i][j]=-1000000000;
			for (k=i-1;k<j;k++)
				dp[i][j]=max(dp[i][j],dp[i-1][k]+b[i][j]);
		}
	tmp=-1000000000;
	for (i=f;i<=v;i++)
		tmp=max(tmp,dp[f][i]);
	printf("%d",tmp);
	return 0;
}
