#include <stdio.h>
#include <set>
using namespace std;
set<int> st;
int mp[6][6];
const int dx[5]={0,0,0,-1,1},dy[5]={0,1,-1,0,0};
void dfs(int x,int y,int res,int k)
{
	if (k==6)
		st.insert(res);
	else
	{
		int ox,oy,i;
		for (i=1;i<=4;i++)
		{
			ox=x+dx[i];
			oy=y+dy[i];
			if (ox>0&&ox<=5&&oy>0&&oy<=5)
				dfs(ox,oy,res*10+mp[ox][oy],k+1);
		}
	}
}
int main()
{
	int i,j;
	for (i=1;i<=5;i++)
		for (j=1;j<=5;j++)
			scanf("%d",&mp[i][j]);
	for (i=1;i<=5;i++)
		for (j=1;j<=5;j++)
			dfs(i,j,mp[i][j],1);
	printf("%d",st.size());
	return 0;
}
