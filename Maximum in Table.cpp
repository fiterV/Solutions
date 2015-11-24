#include <iostream>
using namespace std;
int a[11][11];
int main()
{
	int i,j,n;
	cin>>n;
	for (i=1;i<=n;i++)
		a[i][1]=1;
	for (j=2;j<=n;j++)
		a[1][j]=1;
	for (i=2;i<=n;i++)
		for (j=2;j<=n;j++)
			a[i][j]=a[i-1][j]+a[i][j-1];
	cout<<a[n][n];
	return 0;
}
