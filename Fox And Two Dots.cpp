#include <iostream>
#define WHITE 0
#define YELLOW 1
#define BLACK 2
using namespace std;
char c[52][52];
int vst[52][52],dx[5]={0,1,-1,0,0},dy[5]={0,0,0,1,-1},n,m;
bool f;
void dfs(int i,int j)
{
	int k;
	if (i<1||i>n||j<1||j>m)
		return;
	vst[i][j]=YELLOW;
	for (k=1;k<=4;k++)
	{
		if (vst[i+dx[k]][j+dy[k]]==BLACK&&c[i+dx[k]][j+dy[k]]==c[i][j])
			f=true;
		else if (vst[i+dx[k]][j+dy[k]]==WHITE&&c[i+dx[k]][j+dy[k]]==c[i][j])
			dfs(i+dx[k],j+dy[k]);
	}
	vst[i][j]=BLACK;
}
int main()
{
	int i,j;
	cin>>n>>m;
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			cin>>c[i][j];
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			if (vst[i][j]==WHITE)
				dfs(i,j);
	if (f)
		cout<<"Yes";
	else
		cout<<"No";
}
