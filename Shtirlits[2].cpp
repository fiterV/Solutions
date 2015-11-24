#include <iostream>
#define big(x,y) ((ans[x+1][y]>ans[x][y])+(ans[x-1][y]>ans[x][y])+(ans[x][y+1]>ans[x][y])+(ans[x][y-1]>ans[x][y]))
using namespace std;
int n,mp[5][5],ans[5][5];
bool dfs(int k)
{
	int i,j,_,x=k/3+1,y=k%3+1;
	bool t;
	for (i=1;i<=9;i++)
	{
		ans[x][y]=i;
		if (k==n*n-1)
		{
			t=true;
			for (j=1;j<=n;j++)
			{
				for (_=1;_<=n;_++)
					if (big(j,_)!=mp[j][_])
					{
						t=false;
						break;
					}
				if (!t)
					break;
			}
			if (t)
				return true;
		}
		else
		{
			if (big(x,y)>mp[x][y])
				continue;
			if (dfs(k+1))
				return true;
		}
	}
	ans[x][y]=0;
	return false;
}
int main()
{
	int i,j;
	cin>>n;
	for (i=1;i<=n;i++)
		for (j=1;j<=n;j++)
			cin>>mp[i][j];
	if (dfs(0))
		for (i=1;i<=n;i++)
		{
			for (j=1;j<=n;j++)
				cout<<ans[i][j]<<" ";
			cout<<endl;
		}
	else
		cout<<"NO SOLUTION";
	return 0;
}
