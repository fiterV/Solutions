#include <stdio.h> 
int main()
{
	int a,b,ca,cb=0,ans=0;
	scanf("%d%d",&a,&b);
	ca=a;
	while (ca)
	{
		ans+=ca;
		cb+=ca;
		ca=cb/b;
		cb%=b;
	}
	printf("%d",ans);
	return 0;
}
