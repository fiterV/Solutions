#include <stdio.h>
#include <queue>
using namespace std;
queue<pair<int,int> > q;
bool vst[20001];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	q.push(make_pair(n,0));
	vst[n]=true;
	for (;;)
	{
		pair<int,int> t=q.front();
		q.pop();
		if (t.first==m)
		{
			printf("%d",t.second);
			return 0;
		}
		if (2*t.first<=2*m&&!vst[2*t.first])
		{
			q.push(make_pair(t.first*2,t.second+1));
			vst[t.first*2]=true;
		}
		if (t.first-1>0&&!vst[t.first-1])
		{
			q.push(make_pair(t.first-1,t.second+1));
			vst[t.first-1]=true;
		}
	}
}
