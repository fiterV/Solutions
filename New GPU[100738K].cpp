#include <stdio.h>
#include <math.h>
#define EPS 0.000001
#define abs(a) ((a)>0?(a):-(a))
double ksf(long long a)
{
	double l,r,m;
	l=0;
	r=sqrt(a);
	while (r-l>EPS)
	{
		m=(l+r)/2;
		if (m*m*m>(double)a)
			r=m;
		else
			l=m;
	}
	return l;
}
int main()
{
	int a,b,p;
	long long l,r,m;
	scanf("%d%d%d",&a,&b,&p);
	l=1;
	r=1000000000000000000;
	while (l+1<r)
	{
		m=(l+r)/2;
		//printf("%I64d %I64d %I64d %f\n",l,r,m,(double)a*ksf(m)+(double)b*sqrt(m));
		if ((double)a*ksf(m)+(double)b*sqrt(m)-(double)p>EPS)
			r=m;
		else
			l=m+1;
	}
	printf("%I64d",l);
	return 0;
}
