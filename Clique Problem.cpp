#include <stdio.h>
#include <algorithm>
using namespace std;
pair<int,int> p[200001];
int main()
{
	int n,i,t1,t2,cur=-1000000000,cnt=0;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%d%d",&t1,&t2);
		p[i]=make_pair(t1+t2,t1-t2);
	}
	sort(p+1,p+n+1);
	for (i=1;i<=n;i++)
		if (p[i].second>=cur)
		{
			cnt++;
			cur=p[i].first;
		}
	printf("%d",cnt);
	return 0;
}
