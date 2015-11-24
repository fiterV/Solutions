#include <iostream>
#include <set>
#include <math.h>
using namespace std;
char mp[102][102];
int dx[5]={0,0,0,1,-1},dy[5]={0,1,-1,0,0};
int main()
{
    int n,m,i,j,k,ans;
    char p,t;
    cin>>n>>m>>p;
    for (i=1;i<=n;i++)
    	for (j=1;j<=m;j++)
    		cin>>mp[i][j];
    set<char> s;
    for (i=1;i<=n;i++)
    	for (j=1;j<=m;j++)
    		for (k=1;k<=4;k++)
    		{
    			t=mp[i+dx[k]][j+dy[k]];
    			if (t!='.'&&t!=p)
    				s.insert(t);
			}
    ans=s.size();
	cout<<ans;
    return 0;
}
