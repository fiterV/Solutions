#include <iostream>
#include <string.h>
#define min(a,b) (a<b?a:b)
using namespace std;
int dp[1001][2],pf[1001][2],n,m,x,y;
int dfs(int m,bool b)
{
	if (m==0)
		return 0;
	int& rec=dp[m][b],i;
	if (rec!=-1)
		return rec;
	rec=1000000000;
	for (i=x;i<=y;i++)
		rec=min(rec,dfs(m-i,!b)+pf[m]-pf[m-i]);
	return rec;
}
int main()
{
	int i,j;
	char t;
	cin>>n>>m>>x>>y;
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
		{
			cin>>t;
			if (t=='#')
				pf[j][0]++;
			else
				pf[j][1]++;
		}
	memset(dp,-1,sizeof(dp));
	for (j=1;j<=m;j++)
	{
		pf[j][0]+=pf[j-1][0];
		pf[j][1]+=pf[j-1][1];
	}
	cout<<min(dfs(m,0),dfs(m,1));
	return 0;
}
