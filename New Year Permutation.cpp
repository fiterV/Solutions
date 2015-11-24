#include <iostream>
using namespace std;
char a[301][301];
bool cr[301];
int vlu[301],vst[301],tm,mn,n;
void dfs(int k)
{
	int i;
	if (!cr[vlu[k]])
		mn=min(mn,vlu[k]);
	vst[k]=tm;
	for (i=1;i<=n;i++)
		if (a[k][i]=='1'&&vst[i]!=vst[k])
			dfs(i);
}
int main()
{
	int i,j;
	cin>>n;
	for (i=1;i<=n;i++)
		cin>>vlu[i];
	for (i=1;i<=n;i++)
		for (j=1;j<=n;j++)
			cin>>a[i][j];
	for (i=1;i<=n;i++)
	{
		tm++;
		mn=n;
		dfs(i);
		cr[mn]=true;
		cout<<mn<<" ";
	}
	return 0;
}
