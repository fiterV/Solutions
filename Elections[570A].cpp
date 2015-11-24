#include <stdio.h>
int v[101][101],w[101],nm[101];
int main()
{
	int n,m,i,j,mxn,mxi;
	scanf("%d%d",&n,&m);
	for (i=1;i<=m;i++)
		for (j=1;j<=n;j++)
			scanf("%d",&v[i][j]);
	for (i=1;i<=m;i++)
	{
		mxn=-1;
		mxi=0;
		for (j=1;j<=n;j++)
			if (v[i][j]>mxn)
			{
				mxn=v[i][j];
				mxi=j;
			}
		w[i]=mxi;
	}
	for (i=1;i<=m;i++)
		nm[w[i]]++;
	mxn=-1;
	mxi=0;
	for (i=1;i<=n;i++)
		if (nm[i]>mxn)
		{
			mxn=nm[i];
			mxi=i;
		}
	printf("%d",mxi);
	return 0;
}
