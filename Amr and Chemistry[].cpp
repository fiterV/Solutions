#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
int c[100001],s[100001],dist[100001],par[100001];
int main()
{
	int n,i,x,ans=1000000000;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		queue<int> q;
		scanf("%d",&x);
		q.push(x);
		dist[x]=0;
		par[x]=i;
		while (!q.empty())
		{
			int f=q.front();
			q.pop();
			c[f]++;
			s[f]+=dist[f];
			if (f&&par[f>>1]!=i)
			{
				dist[f>>1]=dist[f]+1;
				par[f>>1]=i;
				q.push(f>>1);
			}
			if ((f<<1)<=100000&&par[f<<1]!=i)
			{
				dist[f<<1]=dist[f]+1;
				par[f<<1]=i;
				q.push(f<<1);
			}
		}
	}
	for (i=1;i<=100000;i++)
		if (c[i]==n)
			ans=min(ans,s[i]);
	printf("%d",ans);
	return 0;
}
