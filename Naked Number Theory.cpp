#include <stdio.h>
#include <math.h>
#define max(a,b) (a>b?a:b)
int phi[1000001],prime[1000001];
bool fg[1000001];
void shai()
{
	int tot=0,i,j;
	for (i=2;i<=1000001;i++)
	{
		if (!fg[i])
		{
			prime[++tot]=i;
			phi[i]=i-1;
		}
		for (j=1;j<=tot;j++)
		{
			if (i*prime[j]>1000001)
				break;
			fg[i*prime[j]]=true;
			phi[i*prime[j]]=phi[i]*phi[prime[j]];
		}
	}
}
int ksm(int a,int b,int mod)
{
	if (b==0)
		return 1;
	long long rec=ksm(a,b>>1,mod);
	rec=(rec*rec)%mod;
	if (b&1)
		rec=(rec*a)%mod;
	return rec;
}
int main()
{
	int T,a,n,p,i,ans;
	shai();
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&a,&n);
		p=phi[n];
		ans=0;
		for (i=1;i<=(int)sqrt(p);i++)
			if (p%i==0)
			{
				if (ksm(a,i,n)==1)
					ans=max(ans,i);
				if (ksm(a,p/i,n)==1)
					ans=max(ans,p/i);
			}
		printf("%d\n",ans);
	}
	return 0;
}
