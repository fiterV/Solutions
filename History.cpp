#include <iostream>
#include <algorithm>
using namespace std;
pair<int,int> p[100001];
int main()
{
	int n,i,mx,cnt=0;
	cin>>n;
	for (i=1;i<=n;i++)
		cin>>p[i].first>>p[i].second;
	sort(p,p+n);
	mx=-1;
	for (i=1;i<=n;i++)
		if (p[i].second<mx) cnt++; else mx=p[i].second;
	cout<<cnt;
	return 0;
}
