#include <stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
int d[101][101],qzh[101][101][101];
int main()
{
	int n,i,j,k,l,sm,ans=-1000000000;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
		for (j=1;j<=n;j++)
			scanf("%d",&d[i][j]);
	for (i=1;i<=n;i++)
		for (j=i;j<=n;j++)
		{
			sm=0;
			for (k=1;k<=n;k++)
			{
				for (l=i;l<=j;l++)
					sm+=d[k][l];
				qzh[i][j][k]=sm;
			}
		}
	for (i=1;i<=n;i++)
		for (j=i;j<=n;j++)
			for (k=1;k<=n;k++)
				for (l=k;l<=n;l++)
					ans=max(ans,qzh[i][j][l]-qzh[i][j][k-1]);
	printf("%d",ans);
	return 0;
}
