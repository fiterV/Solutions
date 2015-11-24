#include <stdio.h>
#include <string.h>
#include <algorithm>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int l[16],ans,n,dp[1<<16];
bool used[16];
struct sol
{
	int a,b,c;
	bool operator<(const sol& d)const
	{
		if (a!=d.a)
			return a<d.a;
		if (b!=d.b)
			return b<d.b;
		return c<d.c;
	}
};
int dfs(int used,int cnt)
{
	int i,j,k,t=used,rec=0;
	if (dp[used]!=-1)
		return dp[used];
	for (i=1;i<=n-2;i++)
		if (!(t&(1<<i)))
		{
			t|=1<<i;
			for (j=i+1;j<=n-1;j++)
				if (!(t&(1<<j)))
				{
					t|=1<<j;
					for (k=j+1;k<=n;k++)
						if (!(t&(1<<k)))
						{
							t|=1<<k;
							if (l[i]+l[j]>l[k])
								rec=max(rec,dfs(t,cnt+1)+1);
							t&=~(1<<k);
						}
					t&=~(1<<j);
				}
			t&=~(1<<i);
		}
	return dp[used]=rec;
}
int main()
{
	int i;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
		scanf("%d",l+i);
	sort(l+1,l+n+1);
	memset(dp,-1,sizeof(dp));
	printf("%d",dfs(0,0));
	return 0;
}
