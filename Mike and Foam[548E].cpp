#include <stdio.h>
#include <vector>
using namespace std;
bool used[200001];
int pc[500001];
vector<int> d[200001];
long long c[500001];
void init()
{
	int i,j;
	pc[1]=1;
	for (i=1;i<=500000;i++)
		for (j=i<<1;j<=500000;j+=i)
			pc[j]-=pc[i];
}
int main()
{
	int n,q,i,j,x,tmp;
	long long ans=0;
	scanf("%d%d",&n,&q);
	init();
	for (i=1;i<=n;i++)
	{
		scanf("%d",&x);
		for (j=1;j*j<=x;j++)
			if (x%j==0)
			{
				d[i].push_back(j);
				if (x/j!=j)
					d[i].push_back(x/j);
			}
	}
	while (q--)
	{
		scanf("%d",&x);
		for (i=0;i<d[x].size();i++)
		{
			tmp=d[x][i];
			ans-=c[tmp]*(c[tmp]-1)/2*pc[tmp];
			if(used[x])
				c[tmp]--;
			else
				c[tmp]++;
			ans+=c[tmp]*(c[tmp]-1)/2*pc[tmp];
		}
		used[x]^=1;
		printf("%I64d\n",ans);
	}
	return 0;
}
