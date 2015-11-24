#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
using namespace std;
struct edge
{
	int from,to,cost;
	edge(){}
	edge(int _f,int _t,int _c){from=_f;to=_t;cost=_c;}
};
struct node
{
	int q5,q6,k;
	node(){}
	node(int _c,int _q5,int _q6,int _k){q5=_q5;q6=_q6;k=_k;}
};
vector<edge> mp;
vector<int> fm;
queue<node> q;
int par[1001],ans;
bool cmp(const edge& a,const edge& b)
{
	return a.cost<b.cost;
}
int fnd(int x)
{
	return par[x]==x?par[x]:par[x]=fnd(par[x]);
}
int main()
{
	int n,m,i,t1,t2,t3,cnt=0,p5,p6,q5,q6;
	scanf("%d%d",&n,&m);
	for (i=1;i<=m;i++)
	{
		scanf("%d%d%d",&t1,&t2,&t3);
		mp.push_back(edge(t1,t2,t3));
	}
	scanf("%d%d%d%d",&p5,&q5,&p6,&q6);
	for (i=1;i<=n;i++)
		par[i]=i;
	sort(mp.begin(),mp.end(),cmp);
	for (i=0;i<mp.size();i++
		if (fnd(mp[i].from)!=fnd(mp[i].to))
		{
			par[fnd(mp[i].from)]=fnd(mp[i].to);
			fm.push_back(mp[i].cost);
			cnt++;
			if (cnt==n-1)
				break;
		}
	if (cnt<n-1)
	{
		printf("Impossible");
		return 0;
	}
	q.push(node(0,0,0));
	while (!q.empty())
	{
		node f=q.front();
		q.pop();
		if (f.k==fm.size())
		{
			
		}
		if (fm[f.k+1]+f.q5<=q5)
			q.push(node(f.q5+fm[f.k+1],f.q6,f.k+1));
		if (fm[f.k+1]+f.q6<=q6)
			q.push(node(f.q5,fm[f.k+1]+f.q6,f.k+1));
	}
	printf("Impossible");
	return 0;
}
