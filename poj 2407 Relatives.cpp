#include <stdio.h>
#include <math.h>
int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}
bool prime(int n)
{
	int i;
	for (i=2;i<=(int)sqrt(n);i++)
		if (n%i==0)
			return false;
	return true;
}
int phi(int n)
{
	int i;
	if (prime(n))
		return n-1;
	for (i=2;i<=n;i++)
		if (n%i==0)
		{
			if (gcd(i,n/i)>1)
				return i*phi(n/i);
			else
				return phi(i)*phi(n/i);
		}
}
int main()
{
	int n;
	while (scanf("%d",&n)!=EOF&&n)
		printf("%d\n",phi(n));
	return 0;
}
