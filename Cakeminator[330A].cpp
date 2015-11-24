#include <stdio.h>
bool eaten[11][11],sbl[11],sbc[11];
int main()
{
	int r,c,i,j,cnt=0;
	char t;
	scanf("%d%d%c",&r,&c,&t);
	for (i=1;i<=r;i++)
	{
		for (j=1;j<=c;j++)
		{
			scanf("%c",&t);
			if (t=='S')
			{
				sbl[i]=true;
				sbc[j]=true;
			}
		}
		scanf("%c",&t);
	}
	for (i=1;i<=r;i++)
		if (!sbl[i])
			for (j=1;j<=c;j++)
				eaten[i][j]=true;
	for (j=1;j<=c;j++)
		if (!sbc[j])
			for (i=1;i<=r;i++)
				eaten[i][j]=true;
	for (i=1;i<=r;i++)
		for (j=1;j<=c;j++)
			cnt+=eaten[i][j];
	printf("%d",cnt);
	return 0;
}
