#include <stdio.h>
int a[100001];
bool dp[100001][101];
int main()
{
	int n,k,i,j;
	while (scanf("%d%d",&n,&k)!=EOF)
	{
		for (i=1;i<=n;i++)
			scanf("%d",a+i);
		dp[0][0]=true;
		for (i=0;i<n;i++)
			for (j=0;j<k;j++)
				if (dp[i][j])
				{
					dp[i+1][((j+a[i+1])%k+k)%k]=true;
					dp[i+1][((j-a[i+1])%k+k)%k]=true;
				}
		if (dp[n][0])
			printf("Divisible\n");
		else
			printf("Not divisible\n");
	}
	return 0;
}
