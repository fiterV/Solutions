#include <iostream>
#include <vector>
using namespace std;
int z;
bool vis[111];
vector<int> v[111];
void vst(int i)
{
	int j;
	vis[i]=true;
	z++;
	for (j=0;j<v[i].size();j++)
		if (!vis[v[i][j]])
			vst(v[i][j]);
}
int main()
{
	int n,m,i,x,y;
	cin>>n>>m;
	for (i=1;i<=m;i++)
	{
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	if (n!=m)
		cout<<"NO";
	else
		vst(1);
		if (z==n)
			cout<<"FHTAGN!";
		else
			cout<<"NO";
	return 0;
}
