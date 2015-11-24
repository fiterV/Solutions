#include <stdio.h>
#define abs(a) (a>0?a:-a)
int p[101];
int main()
{
	int n,k,i,j,l;
	scanf("%d%d",&n,&k);
	for (i=1;i<=n;i++)
		scanf("%d",p+i);
	for (i=1;i<n;i++)
		for (j=i+1;j<=n;j++)
			if (abs(p[i]-p[j])>k)
			{
				printf("NO");
				return 0;
			}
	printf("YES\n");
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=k-p[i]%k;j++)
			for (l=1;l<=p[i]/k;l++)
				printf("%d ",j);
		for (j=k-p[i]%k+1;j<=k;j++)
			for (l=1;l<=p[i]/k+1;l++)
				printf("%d ",j);
		printf("\n");
	}
	return 0;
}
