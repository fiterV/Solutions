#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;
bool row[10][10],cul[10][10],jgg[4][4][10];
int mp[10][10];
pair<int,int> pn[82];
void ___(int x,int y,int t,bool v)
{
	row[x][t]=v;
	cul[y][t]=v;
	jgg[(x-1)/3+1][(y-1)/3+1][t]=v;
}
bool dfs(int cn)
{
	if (cn<=0)
		return true;
	int i,x=pn[cn].first,y=pn[cn].second;
	for (i=1;i<=9;i++)
		if (!(row[x][i]||cul[y][i]||jgg[(x-1)/3+1][(y-1)/3+1][i]))
		{
			mp[x][y]=i;
			___(x,y,i,true);
			if (dfs(cn-1))
				return true;
			___(x,y,i,false);
		}
	return false;
}
int main()
{
	int n,i,j,k,cn;
	char t;
	cin>>n;
	for (k=1;k<=n;k++)
	{
		memset(row,false,sizeof(row));
		memset(cul,false,sizeof(cul));
		memset(jgg,false,sizeof(jgg));
		memset(mp,0,sizeof(mp));
		cn=0;
		for (i=1;i<=9;i++)
			for (j=1;j<=9;j++)
			{
				cin>>t;
				mp[i][j]=t-'0';
				if (t!='0')
				{
					___(i,j,t-'0',true);
				}
				else
					pn[++cn]=make_pair(i,j);
			}
		dfs(cn);
		for (i=1;i<=9;i++)
		{
			for (j=1;j<=9;j++)
				cout<<mp[i][j];
			cout<<endl;
		}
	}
	return 0;
}
