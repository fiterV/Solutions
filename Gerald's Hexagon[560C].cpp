#include <stdio.h>
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
int a[13];
int main()
{
	int i,j,sm=0;
	for (i=1;i<=6;i++)
		scanf("%d",a+i);
	for (i=a[1];i<a[1]+min(a[6],a[2]);i++)
		sm+=2*i+1;
	for (i=min(a[6],a[2]);i<max(a[6],a[2]);i++)
		sm+=2*(a[1]+min(a[6],a[2]));
	for (i=a[4];i<a[4]+min(a[3],a[5]);i++)
		sm+=2*i+1;
	printf("%d",sm);
	return 0;
}
