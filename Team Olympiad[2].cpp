#include <iostream>
#include <algorithm>
using namespace std;
int a[4][5001],m[4];
int main()
{
	int n,i,t,ans;
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>t;
		a[t][++m[t]]=i;
	}
	ans=min(min(m[1],m[2]),m[3]);
	cout<<ans<<endl;
	for (i=1;i<=ans;i++)
		cout<<a[1][i]<<" "<<a[2][i]<<" "<<a[3][i]<<endl;
	return 0;
}
