#include <stdio.h>
#include <algorithm>
using namespace std;
int a[200001],t[200001];
int main()
{
	int n,i;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		t[i]=a[i]-(n-i+1);
	}
	sort(t+1,t+n+1);
	for (i=1;i<=n;i++)
		a[i]=t[i]+(n-i+1);
	for (i=1;i<n;i++)
		if (a[i+1]<a[i])
		{
			printf(":(");
			return 0;
		}
	for (i=1;i<=n;i++)
		printf("%d ",a[i]);
	return 0;
}
