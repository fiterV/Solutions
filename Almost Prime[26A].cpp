#include <iostream>
#include <cmath>
using namespace std;
bool prime(int n)
{
	for (int i=2;i<=sqrt(n);i++)
		if (n%i==0)
			return false;
	return true;
}
bool p[3001];
int main()
{
	int n,i,j,k,cnt=0;
	cin>>n;
	for (i=1;i<=3000;i++)
		p[i]=prime(i);
	for (i=1;i<=n;i++)
	{
		int c=0;
		for (j=2;j<=i;j++)
		{
			if (i%j==0&&p[j])
				c++;
		}
		if (c==2)
			cnt++;
	}
	cout<<cnt;
	return 0;
}
