#include <stdio.h>
#include <queue>
#define max(a,b) (a>b?a:b)
using namespace std;
bool vst[1000001];
queue<int> q;
int main()
{
	int n,i,t,mx=0;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%d",&t);
		q.push(t);
		vst[t]=true;
		mx=max(mx,t);
	}
	while (!q.empty())
	{
		int f=q.front();
		q.pop();
		for (i=1;i<=n;i++)
			if (i+f<=mx&&!vst[i+f])
			{
				q.push(i+f);
				vst[i+f]=true;
			}
	}
	for (i=1;i<=mx;i++)
		if (!vst[i])
		{
			printf("%d",i);
			return 0;
		}
	printf("-1");
	return 0;
}
