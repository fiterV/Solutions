#include <iostream>
#define big(x,y) ((ans[x+1][y]>ans[x][y])+(ans[x-1][y]>ans[x][y])+(ans[x][y+1]>ans[x][y])+(ans[x][y-1]>ans[x][y]))
using namespace std;
int n,mp[5][5],ans[5][5];
bool dfs(int x,int y)
{
	int i,j,k,a=x,b=y+1;
	bool t;
	if (b==n+1)
	{
		a++;
		b=1;
	}
	for (i=1;i<=9;i++)
	{
		ans[x][y]=i;
		if (x==n&&y==n)
		{
			t=true;
			for (j=1;j<=n;j++)
			{
				for (k=1;k<=n;k++)
					if (big(j,k)!=mp[j][k])
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
			if (dfs(a,b))
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
	if (dfs(1,1))
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
