#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
double y[101];
int N,H,R,T;
const double g=10.0;
inline double calc(int k)
{
	if (k<0)
		return H;
	double t=sqrt(2*H/g);
	int x=(int)(k/t);
	if (x%2==0)
	{
		double d=k-x*t;
		return H-g*d*d/2;
	}
	else
	{
		double d=x*t+t-k;
		return H-g*d*d/2;
	}
}
int main()
{
	int z,i;
	scanf("%d",&z);
	while (z--)
	{
		scanf("%d%d%d%d",&N,&H,&R,&T);
		for (i=1;i<=N;i++)
			y[i]=calc(T-i);
		sort(y+1,y+N+1);
		for (i=1;i<=N;i++)
		{
			printf("%.2f",y[i]+2.0*R*i/100.0);
			if (i==N)
				printf("\n");
			else
				printf(" ");
		}
	}
}
