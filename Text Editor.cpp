#include <iostream>
#include <utility>
#include <queue>
#include <memory.h>
using namespace std;
typedef pair<int,int> P;
int dx[5]={0,0,0,1,-1},dy[5]={0,1,-1,0,0},d[101][100001],cnt[101];
queue<P > q;
int main()
{
	int n,i,sx,sy,fx,fy,tx,ty;
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>cnt[i];
		cnt[i]++;
	}
	cin>>sx>>sy>>fx>>fy;
	memset(d,-1,sizeof(d));
	d[sx][sy]=0;
	q.push(make_pair(sx,sy));
	while (!q.empty())
	{
		P f=q.front();
		q.pop();
		for (i=1;i<=4;i++)
		{
			tx=f.first+dx[i];
			ty=min(f.second+dy[i],cnt[tx]);
			if (tx>0&&tx<=n&&ty>0&&ty<=cnt[tx]&&d[tx][ty]==-1)
			{
				q.push(make_pair(tx,ty));
				d[tx][ty]=d[f.first][f.second]+1;
			}
		}
	}
	cout<<d[fx][fy];
	return 0;
}
