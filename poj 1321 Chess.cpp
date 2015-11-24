#include <iostream>
#include <string.h>
using namespace std;
int n,k,cnt,tmp;
bool mp[9][9],vstl[9],vstc[9];
void dfs(int x,int y)
{
	int i,j;
	if (tmp==k)
	{
		cnt+=1;
		return;
	}
	vstl[x]=vstc[y]=true;
	for (i=x+1;i<=n;i++)
		for (j=1;j<=n;j++)
			if (mp[i][j]&&!vstl[i]&&!vstc[j])
			{
				tmp++;
				dfs(i,j);
				tmp--;
			}
	vstl[x]=vstc[y]=false;
}
int main()
{
	int i,j;
	char t;
	while (true)
	{
		cin>>n>>k;
		if (n==-1&&k==-1)
			break;
		memset(mp,false,sizeof(mp));
		memset(vstl,false,sizeof(vstl));
		memset(vstc,false,sizeof(vstc));
		cnt=tmp=0;
		for (i=1;i<=n;i++)
			for (j=1;j<=n;j++)
			{
				cin>>t;
				if (t=='#')
					mp[i][j]=true;
			}
		dfs(0,0);
		cout<<cnt<<endl;
	}
	return 0;
}
