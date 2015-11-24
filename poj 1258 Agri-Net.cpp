#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
struct edge
{
	int from,to,cost;
	inline edge(){}
	inline edge(int _f,int _t,int _c){from=_f;to=_t;cost=_c;}
	inline bool operator<(const edge& b)const
	{
		return cost>b.cost;
	}
};
int par[101];
inline int fnd(int x)
{
	return par[x]==x?x:par[x]=fnd(par[x]);
}
int main()
{
	int n,i,j,x,c,cnt,re;
	edge tmp;
	while (scanf("%d",&n)!=EOF)
	{
		priority_queue<edge> q;
		cnt=0;
		for (i=1;i<=n;i++)
			for (j=1;j<=n;j++)
			{
				scanf("%d",&x);
				if (i!=j)
					q.push(edge(i,j,x));
			}
		for (i=1;i<=n;i++)
			par[i]=i;
		re=n-1;
		while (re)
		{
			tmp=q.top();
			q.pop();
			if (fnd(tmp.from)!=fnd(tmp.to))
			{
				par[fnd(tmp.from)]=fnd(tmp.to);
				cnt+=tmp.cost;
				re--;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
