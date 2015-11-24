#include <stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
int main()
{
	long long n,sm=0,cnt=0;
	scanf("%I64d",&n);
	if (n<=4)
		printf("-1");
	else
	{
		while (n<1000000000)
		{
			cnt++;
			n=(n/2)*(n-n/2);
			sm+=n;
		}
		printf("%I64d",max(cnt,1));
	}
	return 0;
}
