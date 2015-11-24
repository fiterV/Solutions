#include <iostream>
#include <vector>
using namespace std;
vector<int> x[101];
bool vst[201];
void dfs(int k)
{
	int i;
	vst[k]=true;
	for (i=0;i<x[k].size();i++)
		if (!vst[x[k][i]])
			dfs(x[k][i]);
}
int main()
{
	int n,m,i,j,t,y,cnt=0;
	bool f=false;
	cin>>n>>m;
	for (i=1;i<=n;i++)
	{
		cin>>t;
		if (t)
			f=true;
		for (j=1;j<=t;j++)
		{
			cin>>y;
			x[n+y].push_back(i);
			x[i].push_back(n+y);
		}
	}
	for (i=1;i<=n;i++)
		if (!vst[i])
		{
			dfs(i);
			cnt++;
		}
	cout<<cnt-(int)f;
	return 0;
}
