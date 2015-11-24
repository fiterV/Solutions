#include <iostream>
#include <vector>
using namespace std;
vector<int> mp[101];
bool vst[101];
int x[101],y[101];
void src(int k)
{
	int i;
	vst[k]=true;
	for (i=0;i<mp[k].size();i++)
		if (!vst[mp[k][i]])
			src(mp[k][i]);
}
int main()
{
	int n,sm=0,i,j,k=1;
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i];
		for (j=1;j<i;j++)
			if (x[j]==x[i]||y[j]==y[i])
			{
				mp[j].push_back(i);
				mp[i].push_back(j);
			}
	}
	for (i=1;i<=n;i++)
		if (!vst[i])
		{
			src(i);
			sm++;
		}
	cout<<sm-1;
	return 0;
}
