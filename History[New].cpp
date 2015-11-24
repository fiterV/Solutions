#include <iostream>
#include <algorithm>
using namespace std;
struct event
{
	int byear;
	int eyear;
};
bool cmp(event a,event b)
{
	return a.byear<b.byear;
}
event e[100000];
int main()
{
	int n,i,mx=0,cnt=0;
	cin>>n;
	for (i=0;i<n;i++)
		cin>>e[i].byear>>e[i].eyear;
	sort(e,e+n,cmp);
	for (i=0;i<n;i++)
		if (e[i].eyear>mx)
			mx=e[i].eyear;
		else
			cnt++;
	cout<<cnt;
	return 0;
}
