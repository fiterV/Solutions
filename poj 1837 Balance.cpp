#include <stdio.h>
int hk[21],wg[21],dp[21][15001];
int main()
{
	int c,g,i,j,k;
	scanf("%d%d",&c,&g);
	for (i=1;i<=c;i++)
		scanf("%d",hk+i);
	for (i=1;i<=g;i++)
		scanf("%d",wg+i);
	dp[0][7500]=1;
	for (i=1;i<=g;i++)
		for (j=0;j<=15000;j++)
			if (dp[i-1][j])
				for (k=1;k<=c;k++)
					dp[i][j+wg[i]*hk[k]]+=dp[i-1][j];
	printf("%d",dp[g][7500]);
	return 0;
}
