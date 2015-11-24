#include <iostream>
#include <algorithm>
using namespace std;
int err[100001];
int tmp[100001];
int main()
{
	int n,i,j;
	ios::sync_with_stdio(false);
	cin>>n;
	for (i=1;i<=n;i++)
		cin>>err[i];
	for (i=1;i<n;i++)
		cin>>tmp[i];
	sort(err+1,err+n+1);
	sort(tmp+1,tmp+n);
	for (i=1;i<n;i++)
		if (err[i]!=tmp[i])
		{
			cout<<err[i]<<endl;
			break;
		}
	if (i==n)
		cout<<err[n]<<endl;
	for (i=1;i<n-1;i++)
		cin>>err[i];
	sort(err+1,err+n-1);
	for (i=1;i<n;i++)
		if (err[i]!=tmp[i])
		{
			cout<<tmp[i]<<endl;
			break;
		}
	if (i==n)
		cout<<tmp[n-1]<<endl;
	return 0;
}
