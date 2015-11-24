#include <stdio.h>
int seg[100001][2];
int main()
{
	int n,i,tmp,mxi,mxn=0;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%d%d",&seg[i][0],&seg[i][1]);
		int tmp=seg[i][1]-seg[i][0]+1;
		if (tmp>mxn)
		{
			mxi=i;
			mxn=tmp;
		}
	}
	for (i=1;i<=n;i++)
		if (i!=mxi&&(seg[i][0]<seg[mxi][0]||seg[i][1]>seg[mxi][1]))
		{
			printf("-1");
			return 0;
		}
	printf("%d",mxi);
	return 0;
}
