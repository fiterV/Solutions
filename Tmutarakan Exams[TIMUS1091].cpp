#include <stdio.h>
bool vst[51];
long long C(int n,int m)
{
	long long rec=1;
	int i;
	if (m>n)
		return 0;
	if (m>n/2)
		return C(n,n-m);
	for (i=n-m+1;i<=n;i++)
		rec*=i;
	for (i=1;i<=m;i++)
		rec/=i;
	return rec;
}
int main()
{
	int k,s,i,j,l;
	long long cnt=0;
	scanf("%d%d",&k,&s);
	for (i=2;i<=s;i++)
	{
		if (vst[i])
			continue;
		cnt+=C(s/i,k);
		for (j=i,l=1;j<=s;j*=i,l++)
			vst[j]=true;
		if (cnt>=10000)
		{
			printf("10000");
			return 0;
		}
	}
	printf("%lld",cnt);
	return 0;
}
