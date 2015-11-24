#include <stdio.h>
#include <math.h>
#include <string.h>
int n,ans;
char tmp[20];
bool cz[10];
inline bool check(int num)
{
	int i,cnt=0,t=num;
	memset(cz,false,sizeof(cz));
	do
	{
		cz[t%10]=true;
		t/=10;
	}while (t);
	for (i=0;i<=9;i++)
		if (cz[i])
		{
			cnt++;
			if (cnt>2)
				return false;
		}
	return true;
}
void dfs(int cur)
{
	int i;
	if (cur&&cur<=n)
		ans++;
	for (i=0;i<=9;i++)
		if (cur*10+i>0&&cur*10+i<=n&&check(cur*10+i))
			dfs(cur*10+i);
}
int main()
{
	scanf("%d",&n);
	dfs(0);
	printf("%d",ans);
	return 0;
}
