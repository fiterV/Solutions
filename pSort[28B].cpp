#include <stdio.h>
int nm[101],par[101];
inline int fnd(int k)
{
	return par[k]==k?k:par[k]=fnd(par[k]);
}
inline void uni(int a,int b)
{
	if (fnd(a)!=fnd(b))
		par[fnd(a)]=fnd(b);
}
int main()
{
	int n,i,t;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%d",nm+i);
		par[i]=i;
	}
	for (i=1;i<=n;i++)
	{
		scanf("%d",&t);
		if (i-t>0)
			uni(i,i-t);
		if (i+t<=n)
			uni(i,i+t);
	}
	for (i=1;i<=n;i++)
		if (fnd(i)!=fnd(nm[i]))
		{
			printf("NO");
			return 0;
		}
	printf("YES");
	return 0;
}
