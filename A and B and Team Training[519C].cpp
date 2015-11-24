#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n,m,t=0,x,i;
	cin>>n>>m;
	if (n<m)
		x=n,n=m,m=x;
	for (i=1;i<=m&&i*2<=n;i++)
		t=max(t,i+min((m-i)/2,n-i*2));
	cout<<t;
	return 0;
}
