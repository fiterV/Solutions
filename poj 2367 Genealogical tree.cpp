#include <stdio.h>
#include <vector>
using namespace std;
vector<int> mp[101];
bool vst[101];
int topo[101],idx;
void dfs(int k)
{
	int i;
	vst[k]=true;
	for (i=0;i<mp[k].size();i++)
		if (!vst[mp[k][i]])
			dfs(mp[k][i]);
	topo[idx--]=k;
}
int main()
{
	int n,i,t;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
		while (scanf("%d",&t)&&t!=0)
			mp[i].push_back(t);
	idx=n;
	for (i=1;i<=n;i++)
		if (!vst[i])
			dfs(i);
	for (i=1;i<=n;i++)
		printf("%d ",topo[i]);
	return 0;
}
