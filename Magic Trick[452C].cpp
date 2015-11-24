#include <stdio.h>
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	printf("%.16lf",n*m==1?1.0:(double)(1.0/n+(double)(n-1)/n*(m-1)/(n*m-1)));
	return 0;
}
