#include <iostream>
using namespace std;
int n,m,dx[5]={0,-1,1,0,0},dy[5]={0,0,0,1,-1},r2,c2;
bool mp[501][501],vst[501][501];
bool dfs(int x,int y)
{
	if (x==r2&&y==c2)
		return true;
	vst[x][y]=true;
	if (mp[x][y])
		for (;x<n&&mp[x][y];x++);
	mp[x][y]=true;
	int i;
	for (i=1;i<=4;i++)
	{
		int ox=x+dx[i],oy=y+dy[i];
		if (ox>0&&ox<=n&&oy>0&&oy<=m&&!vst[ox][oy])
			if (dfs(ox,oy))
				return true;
	}
	mp[x][y]=false;
	vst[x][y]=false;
	return false;
}
int main()
{
	int i,j,r1,c1;
	char t;
	cin>>n>>m;
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
		{
			cin>>t;
			if (t=='X')
				mp[i][j]=true;
		}
	cin>>r1>>c1>>r2>>c2;
	if (dfs(r1,c1))
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}
