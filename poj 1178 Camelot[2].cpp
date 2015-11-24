#include <string.h>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int dist[9][9];
int dx[9]={0,-2,-2,-1,1,2,2,1,-1},dy[9]={0,-1,1,2,2,1,-1,-2,-2};
int kdx[9]={0,-1,-1,-1,0,0,1,1,1},kdy[9]={0,-1,0,1,-1,1,-1,0,1};
vector<pair<int,int> > mp;
int calc(int x1,int y1,int x2,int y2,bool king)
{
	int i;
	int *tdx,*tdy;
	if (king)
	{
		tdx=kdx;
		tdy=kdy;
	}
	else
	{
		tdx=dx;
		tdy=dy;
	}
	queue<pair<int,int> > q;
	memset(dist,-1,sizeof(dist));
	q.push(make_pair(x1,y1));
	dist[x1][y1]=0;
	while (!q.empty())
	{
		pair<int,int> f=q.front();
		q.pop();
		if (f.first==x2&&f.second==y2)
			return dist[f.first][f.second];
		for (i=1;i<=8;i++)
		{
			int ox=f.first+tdx[i],oy=f.second+tdy[i];
			if (ox>0&&ox<=8&&oy>0&&oy<=8&&dist[ox][oy]==-1)
			{
				dist[ox][oy]=dist[f.first][f.second]+1;
				q.push(make_pair(ox,oy));
			}
		}
	}
	return -1;
}
int main()
{
	char c;
	int t,i,j,x,y,k,ans=1000000000;
	while (cin>>c>>t)
		mp.push_back(make_pair(c-'A'+1,t));
	for (x=1;x<=8;x++)
		for (y=1;y<=8;y++)
			for (k=1;k<mp.size();k++)
			{
				int tmp=0,mcnt=1000000000;
				for (i=1;i<mp.size();i++)
					if (i!=k)
						tmp+=calc(mp[i].first,mp[i].second,x,y,false);
				for (i=1;i<=8;i++)
					for (j=1;j<=8;j++)
						mcnt=min(mcnt,calc(mp[0].first,mp[0].second,i,j,true)+calc(i,j,x,y,false)+calc(mp[k].first,mp[k].second,i,j,false));
				tmp+=mcnt;
				ans=min(ans,tmp);
			}
	cout<<ans;
	return 0;
}
