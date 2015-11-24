#include <stdio.h>
#define abs(a) ((a)>0?(a):-(a))
int iscur(int x1,int y1,int x2,int y2)
{
	return x1<=x2&&y1<=y2||x2<=x1&&y2<=y1;
}
int main()
{
	int x1,y1,x2,y2;
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	x1=abs(x1);
	y1=abs(y1);
	x2=abs(x2);
	y2=abs(y2);
	if (iscur(x1,y1,x2,y2)||iscur(y1,x1,x2,y2)||iscur(x1,y1,y2,x2))
		printf("Yes");
	else
		printf("No");
	return 0;
}
