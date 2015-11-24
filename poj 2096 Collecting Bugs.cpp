#include <stdio.h>
double dp[1005][1005];
int main()
{
	int n,s,i,j;
	scanf("%d%d",&n,&s);
	dp[n][s]=0.0;
	for(i=n;i>=0;i--)
		for(j=s;j>=0;j--)
			if (i!=n||j!=s)
				dp[i][j]=(n*s+(n-i)*j*dp[i+1][j]+i*(s-j)*dp[i][j+1]+(n-i)*(s-j)*dp[i+1][j+1])/(n*s-i*j);
	printf("%.4f\n",dp[0][0]);
	return 0;
}
