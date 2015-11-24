#include <stdio.h>
#define abs(a) ((a)>0?(a):-(a))
int main()
{
	int n,m,i,mxn=0,mxi=1;
	scanf("%d%d",&n,&m);
	//for (i=1;i<=n;i++)
		//if (i!=m&&(abs(i-m)-1)/2+(i>m?n-i:i)>mxn)
		//{
			//mxn=(abs(i-m)-1)/2+(i>m?n-i:i);
			//mxi=i;
		//}
	if (m>n/2)
		printf("%d",n==1?1:m-1);
	else
		printf("%d",m+1);
	//printf("%d",mxi);
	return 0;
}
