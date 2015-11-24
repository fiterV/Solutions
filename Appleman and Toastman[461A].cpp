#include <stdio.h>
#include <algorithm>
using namespace std;
int nm[300001];
long long sm[300001],ans;
void dfs(int begin,int end)
{
	ans+=sm[end]-sm[begin-1];
	if (begin==end)
		return;
	dfs(begin,begin);
	dfs(begin+1,end);
}
int main()
{
	int n,i;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
		scanf("%d",nm+i);
	sort(nm+1,nm+n+1);
	for (i=1;i<=n;i++)
		sm[i]=sm[i-1]+nm[i];
	dfs(1,n);
	printf("%I64d",ans);
	return 0;
}
