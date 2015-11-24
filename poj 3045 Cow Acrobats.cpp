#include <stdio.h>
#include <algorithm>
using namespace std;
pair<int,int> c[50001];
int n,tot;
bool cmp(const pair<int,int>& a,const pair<int,int>& b)
{
	return a.first+a.second>b.first+b.second;
}
int main()
{
	int i,w,s,sm=0,ans=-1000000000;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%d%d",&w,&s);
		c[i]=make_pair(w,s);
		tot+=w;
	}
	sort(c+1,c+n+1,cmp);
	for (i=n;i>=1;i--)
	{
		ans=max(ans,sm-c[i].second);
		sm+=c[i].first;
	}
	printf("%d",ans);
	return 0;
}
