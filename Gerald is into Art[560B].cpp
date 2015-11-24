#include <stdio.h>
#define max(a,b) (a>b?a:b)
int l[7];
int main()
{
	int i,j,k;
	for (i=1;i<=6;i++)
		scanf("%d",l+i);
	for (i=3;i<6;i++)
		for (j=i+1;j<=6;j++)
			for (k=1;k<=2;k++)
				if (max(l[i],l[j])<=l[k]&&l[3]+l[4]+l[5]+l[6]-l[i]-l[j]<=l[3-k]&&(j-i!=1||i==4))
				{
					printf("YES");
					return 0;
				}
	printf("NO");
	return 0;
}
