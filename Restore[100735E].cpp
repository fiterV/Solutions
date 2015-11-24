#include <stdio.h>
long long mp[101][101];
int main()
{
	int n,i,j;
	long long sm=0,sm2=0,inc;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
		for (j=1;j<=n;j++)
			scanf("%I64d",&mp[i][j]);
	for (i=2;i<=n;i++)
		sm+=mp[1][i];
	for (i=2;i<=n;i++)
	{
		long long tmp=sm;
		for (j=1;j<=n;j++)
			tmp-=mp[i][j];
		mp[i][i]=tmp;
		sm2+=tmp;
	}
	inc=(sm-sm2)/(n-1);
	for (i=1;i<=n;i++)
		mp[i][i]+=inc;
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
			printf("%I64d ",mp[i][j]);
		printf("\n");
	}
	return 0;
}
