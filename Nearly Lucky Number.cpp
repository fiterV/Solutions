/*
  Name: Nearly Lucky Number
  Copyright: Nothing
  Author: dyt
  Date: 11/01/15 10:57
  Description: Nearly Lucky Number
*/
#include <stdio.h>
int main()
{
	long long a;
	bool islucky=true;
	int count=0;
	scanf("%I64d",&a);
	while (a>0)
	{
		if (a%10==4||a%10==7) count++;
			a/=10;
	}
	if (count==0) islucky=false;
	while (count>0)
	{
		if (count%10!=4&&count%10!=7) islucky=false;break;
		count/=10;
	}
	if (islucky)
		printf("YES");
	else
		printf("NO");
	return 0;
}
