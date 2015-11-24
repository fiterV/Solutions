#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;
string s[100001];
int a[100001];
string tobin(int x)
{
	string rec;
	while (x)
	{
		rec+=((x&1)+'0');
		x>>=1;
	}
	reverse(rec.begin(),rec.end());
	return rec;
}
int todec(string x)
{
	int i,ans=0;
	for (i=0;i<x.size();i++)
		ans=(ans<<1)+x[i]-'0';
	return ans;
}
int dist(int a,int b)
{
	int ans=0;
	while (__builtin_popcount(a)>__builtin_popcount(b)||a>b)
	{
		a>>=1;
		ans++;
	}
	while (a!=b)
	{
		a<<=1;
		ans++;
	}
	return ans;
}
int main()
{
	int n,pre,i,j,l=0,x,ans=1000000000;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%d",&x);
		s[i]=tobin(x);
		a[i]=x;
	}
	for (i=1;i<=19;i++)
	{
		for (j=1;j<=n;j++)
		{
			if (s[j].size()==i)
			{
				l=i;
				break;
			}
			if (s[j][i-1]!=s[1][i-1])
				break;
		}
		if (l)
			break;
	}
	pre=todec(s[1].substr(0,l));
	for (;pre<=100000;pre<<=1)
	{
		int cnt=0;
		for (i=1;i<=n;i++)
			cnt+=dist(a[i],pre);
		ans=min(ans,cnt);
	}
	printf("%d",ans);
	return 0;
}
