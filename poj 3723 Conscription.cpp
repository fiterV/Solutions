#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
struct edge
{
	int from,to,cost;
	edge(int _f,int _t,int _c){from=_f;to=_t;cost=_c;}
};
vector<edge> mp;
int par[20001];
bool cmp(const edge& a,const edge& b)
{
	return a.cost>b.cost;
}
int fnd(int k)
{
	return par[k]==k?k:par[k]=fnd(par[k]);
}
int main()
{
	int t,n,m,r,x,y,d,i,ans;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d%d",&n,&m,&r);
		for (i=1;i<=n+m;i++)
			par[i]=i;
		mp.clear();
		ans=10000*(n+m);
		for (i=1;i<=r;i++)
		{
			scanf("%d%d%d",&x,&y,&d);
			mp.push_back(edge(x+1,y+1,d));
		}
		sort(mp.begin(),mp.end(),cmp);
		for (i=0;i<mp.size();i++)
			if (fnd(mp[i].from)!=fnd(mp[i].to+n))
			{
				par[fnd(mp[i].from)]=fnd(mp[i].to+n);
				ans-=mp[i].cost;
			}
		printf("%d\n",ans);
	}
	return 0;
}
