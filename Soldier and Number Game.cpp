#include <stdio.h>
#include <math.h>
int nm[5000001];
bool prime(int n)
{
	int i;
	for (i=2;i<sqrt(n);i++)
		if (n%i==0)
			return false;
	return true;
}
int main()
{
	int t,i,j,k,l,t1,t2;
	for (i=2;i<=5000000;i++)
		if (!nm[i])
			for (j=1;i*j<=5000000;j++)
				for (k=i*j;k%i==0;k/=i)
					nm[i*j]++;
	for (i=1;i<=5000000;i++)
		nm[i]+=nm[i-1];
	scanf("%d",&t);
	for (i=1;i<=t;i++)
	{
		scanf("%d%d",&t1,&t2);
		printf("%d\n",nm[t1]-nm[t2]);
	}
	return 0;
}
