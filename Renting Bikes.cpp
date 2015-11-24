#include <stdio.h>
#include <algorithm>
using namespace std;
int n,m,a,b[100001],p[100001];
inline bool cmp(int a,int b)
{
	return a>b;
}
inline bool check(int l)
{
	int i,x=a;
	for (i=1;i<=l;i++)
		if (p[i]>b[l-i+1])
		{
			x-=p[i]-b[l-i+1];
			if (x<0)
				return false;
		}
	return true;
}
int main()
{
	int i,l,r,mid,res,x,ans=0;
	scanf("%d%d%d",&n,&m,&a);
	res=a;
	for (i=1;i<=n;i++)
		scanf("%d",b+i);
	for (i=1;i<=m;i++)
		scanf("%d",p+i);
	sort(b+1,b+n+1,cmp);
	sort(p+1,p+m+1);
	l=0;
	r=min(n,m);
	while (l<=r)
	{
		mid=(l+r)/2;
		if (check(mid))
			l=mid+1;
		else
			r=mid-1;
	}
	l--;
	if (check(1)&&!check(2))
		l=1;
	for (i=1;i<=l;i++)
	{
		x=max(p[l-i+1]-b[i],0);
		res-=p[l-i+1]-x;
		ans+=x;
	}
	ans=max(0,ans-res);
	printf("%d %d",l,ans);
	return 0;
}
