#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
vector<int> mp[49];
vector<vector<int> > lf;
int cnt,cl;
char vst[49];
bool used[49];
stringstream ss;
void dfs(int k)
{
	int i;
	vst[k]=cl;
	lf[cl-1].push_back(k);
	cnt++;
	for (i=0;i<mp[k].size();i++)
		if (!vst[mp[k][i]])
			dfs(mp[k][i]);
}
int main()
{
	int n,m,i,j,t,t1,t2,tmp;
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
			cl++;
			lf.push_back(vector<int>());
			dfs(i);
			if (cnt>3)
			{
				cout<<-1;
				return 0;
			}
		}
	for (i=0;i<lf.size();i++)
	{
		if (used[i])
			continue;
		for (j=0;j<lf[i].size();j++)
			ss<<lf[i][j]<<" ";
		used[i]=true;
		if (lf[i].size()<3)
		{
			tmp=lf[i].size();
			for (j=i+1;j<lf.size();j++)
				if (lf[j].size()+tmp==3&&!used[j])
				{
					for (t=0;t<lf[j].size();t++)
						ss<<lf[j][t]<<" ";
					used[j]=true;
					tmp+=lf[j].size();
				}
			if (tmp<3)
			{
				for (j=i+1;j<lf.size();j++)
					if (lf[j].size()+tmp<=3&&!used[j])
					{
						for (t=0;t<lf[j].size();t++)
							ss<<lf[j][t]<<" ";
						used[j]=true;
						tmp+=lf[j].size();
					}
				for (j=i+1;j<lf.size();j++)
					if (lf[j].size()+tmp==3&&!used[j])
					{
						for (t=0;t<lf[j].size();t++)
							ss<<lf[j][t]<<" ";
						used[j]=true;
						tmp+=lf[j].size();
					}
				if (tmp<3)
				{
					cout<<-1;
					return 0;
				}
			}
		}
		ss<<endl;
	}
	cout<<ss.str();
	return 0;
}
