#include <stdio.h>
#include <algorithm>
using namespace std;
int A[5010];
int solve(int l,int r,int h)
{
    if (l>r)
		return 0;
    int loc=-1,mini=1<<30,sum=0;
    for (int i=l;i<=r;i++)
	{
        if (mini>A[i])
        {
            mini=A[i];
            loc=i;
        }
        if (A[i]>h)
            sum++;
    }
    return min(sum,solve(l,loc-1,max(A[loc],h))+solve(loc+1,r,max(A[loc],h))+max(A[loc]-h,0));
}
int main()
{
	int n;
	scanf("%d",&n);
    for (int i=1;i<=n;i++)
		scanf("%d",A+i);
    printf("%d\n",solve(1,n,0));
    return 0;
}
