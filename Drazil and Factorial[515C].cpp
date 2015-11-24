#include <iostream>
using namespace std;
int a[16];
int main()
{
	int n,i,pro=1;
	char t;
	bool f=false;
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>t;
		a[i]=t-'0';
		if (a[i]!=0)
			pro*=a[i];
	}
	return 0;
}
