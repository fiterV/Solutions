#include <stdio.h>
#include <string.h>
#define min(a,b) ((a)<(b)?(a):(b))
int nm[100001],b[100001],n,m;
bool check(long long z)
{
	int pos=n,i;
	memcpy(b,nm,sizeof(nm));
	for (i=1;i<=m;i++)
	{
		long long tr=z,tmp;
		while (!b[pos]&&pos)
			pos--;
		tr-=pos;
		while (tr>0)
		{
			while (!b[pos]&&pos)
				pos--;
			if (!pos)
				break;
			tmp=min(tr,b[pos]);
			tr-=tmp;
			b[pos]-=tmp;
		}
	}
	for (i=1;i<=n;i++)
		if (b[i]>0)
			return false;
	return true;
}
int main()
{
	int i;
	long long l,r,z,s=0;
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++)
	{
		scanf("%d",nm+i);
		s+=nm[i];
	}
	l=2;
	r=s+n;
	while (l<r)
	{
		z=(l+r)/2;
		if (check(z))
			r=z;
		else
			l=z+1;
	}
	printf("%I64d",r);
	return 0;
}
