#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int a[1001],b[1001];
bool used[1001];
bool cmp(const int a,const int b)
{
	return a>b;
}
int main()
{
	int n,i,j,cnt,idx;
	while (scanf("%d",&n)!=EOF&&n)
	{
		cnt=0;
		idx=1;
		memset(used,false,sizeof(used));
		for (i=1;i<=n;i++)
			scanf("%d",a+i);
		for (i=1;i<=n;i++)
			scanf("%d",b+i);
		sort(a+1,a+n+1,cmp);
		sort(b+1,b+n+1,cmp);
		for (i=1;i<=n;i++)
		{
			while (used[idx])
				idx++;
			for (j=1;j<=n;j++)
				if (!used[j]&&a[i]>b[j])
					break;
			if (j>n)
			{
				used[idx]=true;
				if (a[i]<b[idx])
					cnt--;
			}
			else
			{
				used[j]=true;
				cnt++;
			}
		}
		printf("%d\n",cnt*200);
	}
	return 0;
}
