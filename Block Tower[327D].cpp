#include <iostream>
#include <sstream>
#include <string>
using namespace std;
stringstream ans;
int n,m,dx[5]={0,-1,1,0,0},dy[5]={0,0,0,-1,1},k;
char mp[501][501];
bool vst[501][501];
void dfs(int x,int y,bool root)
{
	int i,a,b;
	k++;
	ans<<"B "<<x<<" "<<y<<endl;
	vst[x][y]=true;
	for (i=1;i<=4;i++)
	{
		a=x+dx[i];
		b=y+dy[i];
		if (a>0&&a<=n&&b>0&&b<=m&&mp[a][b]=='.'&&!vst[a][b])
			dfs(a,b,false);
	}
	if (!root)
	{
		k+=2;
		ans<<"D "<<x<<" "<<y<<endl;
		ans<<"R "<<x<<" "<<y<<endl;
	}
}
int main()
{
	int i,j;
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			cin>>mp[i][j];
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			if (!vst[i][j]&&mp[i][j]=='.')
				dfs(i,j,true);
	cout<<k<<endl;
	cout<<ans.str();
	return 0;
}
