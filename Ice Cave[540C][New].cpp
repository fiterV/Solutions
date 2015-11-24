#include <iostream>
#include <queue>
using namespace std;
char vst[502][502];
typedef pair<int,int> pii;
int dx[5]={0,1,-1,0,0},dy[5]={0,0,0,-1,1};
int main()
{
	int n,m,r1,c1,r2,c2,i,j;
	char t;
	queue<pii> q;
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
		{
			cin>>t;
			if (t=='X')
				vst[i][j]=1;
		}
	cin>>r1>>c1>>r2>>c2;
	q.push(make_pair(r1,c1));
	while (!q.empty())
	{
		pii p=q.front();
		q.pop();
		for (i=1;i<=4;i++)
		{
			int ox=p.first+dx[i],oy=p.second+dy[i];
			if (ox>=1&&oy>=1&&ox<=n&&oy<=m&&(vst[ox][oy]==0||ox==r2&&oy==c2&&vst[ox][oy]==1))
			{
				q.push(make_pair(ox,oy));
				vst[ox][oy]++;
			}
		}
	}
	if (vst[r2][c2]==2)
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}
