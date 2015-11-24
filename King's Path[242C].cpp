#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
#define INFINATE 1000000000
using namespace std;
map<pair<int,int>,int> mp;
queue<pair<int,int> > q;
int dx[9]={0,-1,1,0,0,-1,-1,1,1},dy[9]={0,0,0,-1,1,-1,1,-1,1};
int main()
{
	int sx,sy,ex,ey,n,i,t1,t2,t3,j,ox,oy;
	ios::sync_with_stdio(false);
	cin>>sx>>sy>>ex>>ey;
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>t1>>t2>>t3;
		for (j=t2;j<=t3;j++)
			mp[make_pair(t1,j)]=INFINATE;
	}
	mp[make_pair(sx,sy)]=0;
	q.push(make_pair(sx,sy));
	while (!q.empty())
	{
		pair<int,int> p=q.front();
		q.pop();
		for (i=1;i<=8;i++)
		{
			ox=p.first+dx[i];
			oy=p.second+dy[i];
			if (mp.find(make_pair(ox,oy))!=mp.end()&&mp[make_pair(ox,oy)]>mp[make_pair(p.first,p.second)]+1/*&&ox>0&&ox<=1000000000&&oy>0&&oy<=1000000000*/)
			{
				q.push(make_pair(p.first+dx[i],p.second+dy[i]));
				mp[make_pair(p.first+dx[i],p.second+dy[i])]=mp[make_pair(p.first,p.second)]+1;
			}
		}
	}
	if (mp[make_pair(ex,ey)]==INFINATE)
		cout<<-1;
	else
		cout<<mp[make_pair(ex,ey)];
	return 0;
}
