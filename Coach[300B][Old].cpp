#include <iostream>
#include <vector>
using namespace std;
vector<int> mp[49];
int cnt,num,vst[49],t[49][5],n;
void dfs(int k)
{
	int i;
	cnt++;
	vst[k]=num;
	for (i=0;i<mp[k].size();i++)
		if (!vst[mp[k][i]])
			dfs(mp[k][i]);
}
int getidx(int str,int num)
{
	int i;
	for (i=str-1;i>=1;i--)
		if (t[i][0]==num&&t[i][4])
			return i;
	return -1;
}
int main()
{
	int m,i,t1,t2,j;
	cin>>n>>m;
	for (i=1;i<=m;i++)
	{
		cin>>t1>>t2;
		mp[t1].push_back(t2);
		mp[t2].push_back(t1);
	}
	for (i=1;i<=n;i++)
		if (!vst[i])
		{
			cnt=0;
			num++;
			dfs(i);
			if (cnt>3)
			{
				cout<<-1;
				return 0;
			}
		}
	for (i=1;i<=n;i++)
	{
		t[vst[i]][t[vst[i]][0]+1]=i;
		t[vst[i]][0]++;
	}
	for (i=1;i<=n;i++)
	{
		if (t[i][0]==1)
		{
			int idx=getidx(i,2);
			if (idx==-1)
			{
				idx=getidx(i,1);
				
			}
		}
	}
	return 0;
}
