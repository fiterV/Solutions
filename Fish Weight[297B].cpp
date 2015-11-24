#include <stdio.h>
#include <algorithm>
using namespace std;
int a[100001],b[100001];
inline bool cmp(const int a,const int b)
{
	return a>b;
}
int main()
{
	int n,m,k,i;
	scanf("%d%d%d",&n,&m,&k);
	if (n>m)
	{
		printf("YES");
		return 0;
	}
	for (i=1;i<=n;i++)
		scanf("%d",a+i);
	sort(a+1,a+n+1,cmp);
	for (i=1;i<=m;i++)
		scanf("%d",b+i);
	sort(b+1,b+m+1,cmp);
	for (i=1;i<=min(n,m);i++)
		if (a[i]>b[i])
		{
			printf("YES");
			return 0;
		}
	printf("NO");
	return 0;
}
