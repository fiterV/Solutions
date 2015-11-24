#include <stdio.h>
#include <vector>
using namespace std;
bool npr[1001];
int main()
{
	int n,m,i,j,cnt=0;
	vector<int> pri;
	scanf("%d%d",&n,&m);
	npr[1]=true;
	for (i=2;i<=n;i++)
		if (!npr[i])
			for (j=2;i*j<=n;j++)
				npr[i*j]=true;
	for (i=1;i<=n;i++)
		if (!npr[i])
			pri.push_back(i);
	for (i=0;i<pri.size()-1;i++)
	{
		int tmp=pri[i]+pri[i+1]+1;
		if (tmp<=n&&!npr[tmp])
			cnt++;
	}
	if (cnt>=m)
		printf("YES");
	else
		printf("NO");
	return 0;
}
