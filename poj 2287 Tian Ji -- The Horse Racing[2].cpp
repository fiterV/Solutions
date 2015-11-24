#include <stdio.h>
#include <algorithm>
using namespace std;
int tian[1001],king[1001];
int main()
{
	int n,i,ans,max1,max2,min1,min2,cnt; 
	while (scanf("%d", &n)&&n)
	{
		for (i=1;i<=n;i++)
			scanf("%d",tian+i);
		for (i=1;i<=n;i++)
			scanf("%d",king+i);
		sort(tian+1,tian+n+1);
		sort(king+1,king+n+1);
		ans=0,max1=max2=n,min1=min2=1,cnt=1;
		while ((cnt++)<=n)
		{
			if (tian[max1]>king[max2])
			{
				ans+=200;
				max1--;
				max2--;
			}
			else if (tian[max1]<king[max2])
			{
				ans-=200;
				min1++;
				max2--;
			}
			else if (tian[min1]>king[min2])
			{
				ans+=200;
				min1++;
				min2++;
			}
			else
			{
				if (tian[min1]<king[max2])
					ans-=200;
				min1++;
				max2--;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
