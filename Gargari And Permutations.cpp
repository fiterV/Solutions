#include <stdio.h>
#include <vector>
using namespace std;
int ord[6][1001],nm[6][1001],dp[1001];
vector<int> mp[1001];
bool vst[1001];
int dfs(int k)
{
	int i;
	if (vst[k])
		return dp[k];
	vst[k]=true;
	for (i=0;i<mp[k].size();i++)
		dp[k]=max(dp[k],dfs(mp[k][i])+1);
	return dp[k];
}
int main()
{
	int n,k,i,j,l,x,ans=0;
	scanf("%d%d",&n,&k);
	for (i=1;i<=k;i++)
		for (j=1;j<=n;j++)
		{
			scanf("%d",&x);
			nm[i][j]=x;
			ord[i][x]=j;
		}
	for (i=1;i<n;i++)
		for (j=i+1;j<=n;j++)
		{
			int u=nm[1][i],v=nm[1][j];
			for (l=2;l<=k;l++)
				if (ord[l][u]>ord[l][v])
					break;
			if (l>k)
				mp[j].push_back(i);
		}
	for (i=1;i<=n;i++)
		if (!vst[i])
			ans=max(ans,dfs(i));
	printf("%d",ans+1);
	return 0;
}
