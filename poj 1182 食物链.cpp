#include <stdio.h>
int par[150001];
int fnd(int x)
{
	return par[x]==x?x:par[x]=fnd(par[x]);
}
inline void uni(int x,int y)
{
	if (fnd(x)!=fnd(y))
		par[fnd(x)]=fnd(y);
}
int main()
{
	int n,k,i,x,y,t,cnt=0,px,py;
	scanf("%d%d",&n,&k);
	for (i=1;i<=3*n;i++)
		par[i]=i;
	while (k--)
	{
		scanf("%d%d%d",&t,&x,&y);
		if (x<=n&&y<=n)
		{
			if (t==1)
			{
				if (fnd(x)==fnd(y+n)||fnd(x)==fnd(y+n+n))
					cnt++;
				else
				{
					uni(x,y);
					uni(x+n,y+n);
					uni(x+n+n,y+n+n);
				}
			}
			else
			{
				if (fnd(x)==fnd(y)||fnd(x+n)==fnd(y)||x==y)
					cnt++;
				else
				{
					uni(x,y+n);
					uni(x+n,y+n+n);
					uni(x+n+n,y);
				}
			}
		}
		else
			cnt++;
	}
	printf("%d",cnt);
	return 0;
}
