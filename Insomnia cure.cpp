#include <stdio.h>
int k,l,m,n,d,i,z;
int main()
{
	scanf("%d%d%d%d%d",&k,&l,&m,&n,&d);
    for (i=1;i<=d;i++)
        if (i%k&&i%l&&i%m&&i%n)
			z+=1;
	printf("%d",d-z);
    return 0;
}
