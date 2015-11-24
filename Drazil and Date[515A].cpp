#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
int main()
{
	long long a,b,s;
	cin>>a>>b>>s;
	if ((abs(a)+abs(b))%2==s%2&&s>=(abs(a)+abs(b)))
		cout<<"Yes";
	else
		cout<<"No";
	return 0;
}
