#include <stdio.h>
bool F[201][201],beat[201][201],win[201];
int main()
{
	int n,i,j,N,l,k,cnt=0;
	bool tmp;
	freopen("inputpoi.in","r",stdin);
	scanf("%d",&n);
	N=2*n;
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
		{
			scanf("%c",&tmp);
			while (tmp==10||tmp==13)
				scanf("%c",&tmp);
			beat[i][j]=beat[i+n][j]=beat[i][j+n]=beat[i+n][j+n]=tmp=='1';
		}
	}
	for (i=1;i<N;i++)
		F[i][i+1]=true;
	for (l=3;l<N;l++)
	{
		for (i=1;i<=N-l+1;i++)
		{
			j=i+l-1;
			for (k=i+1;k<j;k++)
				if (F[i][k]&&F[k][j]&&(beat[i][k]||beat[j][k]))
				{
					F[i][j]=true;
					break;
				}
		}
	}
	for (i=1;i<=n;i++)
		if (F[i][i+n])
		{
			cnt++;
			win[i]=true;
		}
	printf("%d\n",cnt);
	for (i=1;i<=n;i++)
		if (win[i])
			printf("%d\n",i);
	return 0;
}
