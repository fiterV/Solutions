#include <iostream>
using namespace std;
bool bh[100],gh[100];
int main()
{
	int n,m,b,g,i,t;
	bool f=false;
	cin>>n>>m;
	cin>>b;
	for (i=0;i<b;i++)
	{
		cin>>t;
		bh[t]=true;
	}
	cin>>g;
	for (i=0;i<g;i++)
	{
		cin>>t;
		gh[t]=true;
	}
	while (!f)
	{
		f=true;
		for (i=0;i<n*m;i++)
		{
			if (bh[i%n]&&!gh[i%m])
			{
				gh[i%m]=true;
				f=false;
			}
			if (gh[i%m]&&!bh[i%n])
			{
				bh[i%n]=true;
				f=false;
			}
		}
	}
	for (i=0;i<n;i++)
		if (!bh[i])
		{
			cout<<"No";
			return 0;
		}
	for (i=0;i<m;i++)
		if (!gh[i])
		{
			cout<<"No";
			return 0;
		}
	cout<<"Yes";
	return 0;
}
