#include <stdio.h>
#include <algorithm>
using namespace std;
int n,pos[50002];
int check(int k)
{
	int i,cnt=0,added=0;
	for (i=1;i<=n+1;i++)
		if (pos[i]-pos[i-1]+added<k)
		{
			cnt++;
			added=pos[i]-pos[i-1]+added;
		}
		else
			added=0;
	return cnt;
}
int main()
{
	int l,m,i,lef,rig,mid;
	scanf("%d%d%d",&l,&n,&m);
	for (i=1;i<=n;i++)
		scanf("%d",pos+i);
	sort(pos+1,pos+n+1);
	pos[n+1]=l;
	lef=1;
	rig=l+1;
	while (lef<=rig)
	{
		mid=(lef+rig)/2;
		if (check(mid)<=m)
			lef=mid+1;
		else
			rig=mid-1;
	}
	printf("%d",rig);
	return 0;
}
