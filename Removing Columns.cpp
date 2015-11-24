#include <iostream>
using namespace std;
char a[102][102];
bool b[102];
int main()
{
	int n,m,i,j,cc=0;
	cin>>n>>m;
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=m;j++)
			cin>>a[i][j];
		b[i]=true;
	}
	for (j=1;j<=m;j++)
	{
		for (i=2;i<=n;i++)
			if (b[i]&&a[i-1][j]>a[i][j]) break;
		if (i>n)
		{
			for (i=2;i<=n;i++)
				if (b[i]&&a[i-1][j]<a[i][j]) b[i]=false;
		}
		else
			cc++;
	}
	cout<<cc;
	return 0;
}
