#include <iostream>
#include <vector>
using namespace std;
bool prime[16],vst[16];
int n,cnt,st;
void dfs(int k)
{
	int i;
	vst[k]=true;
	cnt++;
	if (cnt==n&&prime[st+k])
	{
		for (i=1;i<=n;i++)
			if (vst[i])
				cout<<i<<" ";
		cout<<endl;
	}
	else if (cnt==n)
	{
		return;
	}
	else
		for (i=1;i<=n;i++)
			if (!vst[i]&&prime[k+i])
				dfs(i);
	cnt--;
	vst[k]=false;
}
int main()
{
	int i,j;
	for (i=2;i<=15;i++)
		prime[i]=true;
	for (i=2;i<=8;i++)
		for (j=2;j<=n/i;j++)
			prime[i*j]=false;
	cin>>n;
	for (i=1;i<=n;i++)
	{
		st=i;
		dfs(i);
	}
	return 0;
}
