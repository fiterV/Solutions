#include <iostream>
using namespace std;
int main()
{
	long long n,m,a;
	cin>>n>>m>>a;
	long long b,c;
	b=(n-1)/a+1;
	c=(m-1)/a+1;
	cout<<b*c<<endl;
	return 0;
}
