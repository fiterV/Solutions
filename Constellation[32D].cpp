#include <stdio.h>
char a[301][301];
int main()
{
	int n,m,k,x,i,j;
	scanf("%d%d%d",&n,&m,&k);
	for (i=1;i<=n;i++)
		scanf("%s",a+i);
	for (x=1;x<=n/2;x++)
		for (i=x;i<=n-x;i++)
			for (j=x;j<=m-x;j++)
				if (a[i][j-1]=='*'&&a[i-x][j-1]=='*'&&a[i+x][j-1]=='*'&&a[i][j-x-1]=='*'&&a[i][j+x-1]=='*'&&!--k)
				{
					printf("%d %d\n%d %d\n%d %d \n%d %d\n%d %d",i,j,i-x,j,i+x,j,i,j-x,i,j+x);
					return 0;
				}
	printf("%d",-1);
	return 0;
}
