#include <stdio.h>
#include <stdlib.h>
#define min(a,b) (a<b?a:b)
char s[1001],t[1001];
int main()
{
	int n,i,cnt=0;
	scanf("%d%*c",&n);
	for (i=1;i<=n;i++)
		scanf("%c",s+i);
	scanf("%*c");
	for (i=1;i<=n;i++)
		scanf("%c",t+i);
	for (i=1;i<=n;i++)
		cnt+=min(abs(s[i]-t[i]),10-abs(s[i]-t[i]));
	printf("%d",cnt);
	return 0;
}
