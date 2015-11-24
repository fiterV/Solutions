#include <stdio.h>
int nm[101];
bool mp[101][101];
int main()
{
	int n,i,j,k,x;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
		scanf("%d",nm+i);
	for (i=1;i<=n;i++)
	{
		scanf("%d",&x);
		mp[i][i]=true;
		if (i-x>=1)
		{
			mp[i][i-x]=true;
			mp[i-x][i]=true;
		}
		if (i+x<=n)
		{
			mp[i][i+x]=true;
			mp[i+x][i]=true;
		}
	}
	for (k=1;k<=n;k++)
		for (i=1;i<=n;i++)
			for (j=1;j<=n;j++)
				if (mp[i][k]&&mp[k][j])
					mp[i][j]=true;
	for (i=1;i<=n;i++)
		if (!mp[i][nm[i]])
		{
			printf("NO");
			return 0;
		}
	printf("YES");
	return 0;
}
