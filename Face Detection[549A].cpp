#include <iostream>
#include <string.h>
using namespace std;
char mp[51][51];
bool fl[256];
int main()
{
	int n,m,i,j,cnt=0;
	cin>>n>>m;
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			cin>>mp[i][j];
	for (i=1;i<n;i++)
		for (j=1;j<m;j++)
		{
			memset(fl,false,sizeof(fl));
			fl[mp[i][j]]=fl[mp[i+1][j]]=fl[mp[i][j+1]]=fl[mp[i+1][j+1]]=true;
			if (fl['f']&&fl['a']&&fl['c']&&fl['e'])
				cnt++;
		}
	cout<<cnt;
	return 0;
}
