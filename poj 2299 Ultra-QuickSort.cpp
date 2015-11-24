#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct node
{
	int value,order;
};
node a[500001];
int n,tree[500001],idx[500001];
inline int query(int x)
{
	int i=x,rec=0;
	while (i>0)
	{
		rec+=tree[i];
		i-=(i&(-i));
	}
	return rec;
}
inline bool cmp(const node& a,const node& b)
{
	return a.value<b.value;
}
inline void modify(int x)
{
	int i=x;
	while (i<=n)
	{
		tree[i]++;
		i+=(i&(-i));
	}
}
int main()
{
	int i,s;
	long long cnt;
	for (;;)
	{
		scanf("%d",&n);
		if (!n)
			break;
		for (i=1;i<=n;i++)
		{
			scanf("%d",&a[i].value);
			a[i].order=i;
		}
		sort(a+1,a+n+1,cmp);
		for (i=1;i<=n;i++)
			idx[a[i].order]=i;
		memset(tree,0,sizeof(tree));
		cnt=0;
		for (i=1;i<=n;i++)
		{
			modify(idx[i]);
			cnt+=i-query(idx[i]);
		}
		printf("%lld\n",cnt);
	}
}
