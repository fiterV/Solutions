#include <stdio.h>
#include <deque>
using namespace std;
struct node
{
	int high;
	bool left;
	int deep;
};
bool mp[2][200001],hi[2][200001];
deque<node> q;
int main()
{
	int n,k,i;
	char t;
	scanf("%d%d",&n,&k);
	getchar();
	for (i=1;i<=n;i++)
	{
		scanf("%c",&t);
		if (t=='-')
			mp[1][i]=true;
	}
	getchar();
	for (i=1;i<=n;i++)
	{
		scanf("%c",&t);
		if (t=='-')
			mp[0][i]=true;
	}
	q.push_back({1,true,0});
	while (!q.empty())
	{
		node tmp,s=q.front();
		q.pop_front();
		if (s.high<1||s.high<=s.deep||(hi[s.left][s.high]&&hi[s.left][s.high]<=s.deep))
			continue;
		if (s.high+k>n)
		{
			printf("YES");
			return 0;
		}
		hi[s.left][s.high]=s.deep;
		if (mp[s.left][s.high+1])
			q.push_back((node){s.high+1,s.left,s.deep+1});
		if (s.high-1>s.deep+1&&mp[s.left][s.high-1])
			q.push_back((node){s.high-1,s.left,s.deep+1});
		if (mp[s.left^1][s.high+k])
			q.push_back((node){s.high+k,s.left^1,s.deep+1});
	}
	printf("NO");
	return 0;
}
