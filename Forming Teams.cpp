#include <iostream>
#include <vector>
#define COLOR int
#define WHITE 0
#define YELLOW 1
#define BLACK 2
using namespace std;
int cnt,dph,dep[101],n,crt;
vector<int> mp[101];
COLOR vst[101];
void dfs(int k)
{
	int i,j;
	vst[k]=YELLOW;
	dep[k]=++dph;
	for (i=0;i<mp[k].size();i++)
		if (vst[mp[k][i]]==YELLOW&&(dep[mp[k][i]]-dph)%2==0)
			cnt++;
		else if (vst[mp[k][i]]==WHITE)
			dfs(mp[k][i]);
	dph--;
	vst[k]=BLACK;
}
int main()
{
	int m,i,t1,t2;
	cin>>n>>m;
	for (i=1;i<=m;i++)
	{
		cin>>t1>>t2;
		mp[t1].push_back(t2);
		mp[t2].push_back(t1);
	}
	for (i=1;i<=n;i++)
		if (vst[i]==WHITE)
			dfs(i);
	if ((n-cnt)%2)
		cout<<cnt+1;
	else
		cout<<cnt;
	return 0;
}
