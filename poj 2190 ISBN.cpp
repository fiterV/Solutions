#include <stdio.h>
int main()
{
	int i,k,rg,sm=0;
	char t;
	for (i=1;i<=10;i++)
	{
		scanf("%c",&t);
		if (t=='?')
			k=i;
		else if (t=='X')
			sm+=10*(11-i);
		else
			sm+=(t-'0')*(11-i);
	}
	rg=k==10?10:9;
	for (i=0;i<=rg;i++)
		if ((sm+(11-k)*i)%11==0)
		{
			printf("%c",i==10?'X':'0'+i);
			return 0;
		}
	printf("-1");
	return 0;
}
