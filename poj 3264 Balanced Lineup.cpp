#include <stdio.h>
#include <math.h>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
int h[50001],mx[300],mn[300];
int main()
{
	int n,q,i,b,j,tmx,tmn,x,y;
	scanf("%d%d",&n,&q);
	for (i=0;i<n;i++)
		scanf("%d",h+i);
	b=(int)sqrt((double)n);
	for (i=0;i<=b;i++)
		mn[i]=1000000000;
	for (i=0;i<n;i++)
	{
		mx[i/b]=max(mx[i/b],h[i]);
		mn[i/b]=min(mn[i/b],h[i]);
	}
	while (q--)
	{
		scanf("%d%d",&x,&y);
		tmx=0;
		tmn=1000000000;
		int l=x-1,r=y;
        while (l<r&&l%b)
        {
        	int H=h[l++];
            tmn=min(tmn,H);
            tmx=max(tmx,H);
        }
        while (l<r&&r%b)
        {
        	int H=h[--r];
            tmn=min(tmn,H);
            tmx=max(tmx,H);
        }
        while (l<r)
        {
            tmn=min(tmn,mn[l/b]);
            tmx=max(tmx,mx[l/b]);
            l+=b;
        }
		printf("%d\n",tmx-tmn);
	}
	return 0;
}
