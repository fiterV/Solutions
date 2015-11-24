#include <stdio.h>
#include <math.h>
int cnt2[5],cnt3[5];
int main()
{
	long long x1,y1,x2,y2,t1,t2,k1,k2;
	scanf("%I64d%I64d%I64d%I64d",&x1,&x2,&y1,&y2);
	t1=x1,t2=x2,k1=y1,k2=y2;
	while (t1%2==0)
	{
		t1/=2;
		cnt2[0]++;
	}
	while (t1%3==0)
	{
		t1/=3;
		cnt3[0]++;
	}
	while (t2%2==0)
	{
		t2/=2;
		cnt2[1]++;
	}
	while (t2%3==0)
	{
		t2/=3;
		cnt3[1]++;
	}
	while (k1%2==0)
	{
		k1/=2;
		cnt2[2]++;
	}
	while (k1%3==0)
	{
		k1/=3;
		cnt3[2]++;
	}
	while (k2%2==0)
	{
		k2/=2;
		cnt2[3]++;
	}
	while (k2%3==0)
	{
		k2/=3;
		cnt3[3]++;
	}
	if (t1*t2!=k1*k2)
		printf("-1");
	else
	{
		int ans=0,x3=cnt3[0]+cnt3[1],y3=cnt3[2]+cnt3[3],x4=cnt2[0]+cnt2[1],y4=cnt2[2]+cnt2[3],xd3=0,yd3=0,xd4=0,yd4=0;
		if (x3>y3)
		{
			xd3=x3-y3;
			x4+=xd3;
			ans+=xd3;
		}
		else if (x3<y3)
		{
			yd3=y3-x3;
			y4+=yd3;
			ans+=yd3;
		}
		if (x4>y4)
		{
			xd4=x4-y4;
			ans+=xd4;
		}
		else if (x4<y4)
		{
			yd4=y4-x4;
			ans+=yd4;
		}
		while (x1%3==0&&xd3)
		{
			x1=x1/3*2;
			xd3--;
		}
		while (x2%3==0&&xd3)
		{
			x2=x2/3*2;
			xd3--;
		}
		while(x1%2==0&&xd4)
		{
			x1/=2;
			xd4--;
		}
		while(x2%2==0&&xd4)
		{
			x2/=2;
			xd4--;
		}
		while (y1%3==0&&yd3)
		{
			y1=y1/3*2;
			yd3--;
		}
		while (y2%3==0&&yd3)
		{
			y2=y2/3*2;
			yd3--;
		}
		while(y1%2==0&&yd4)
		{
			y1/=2;
			yd4--;
		}
		while(y2%2==0&&yd4)
		{
			y2/=2;
			yd4--;
		}
		printf("%d\n%I64d %I64d\n%I64d %I64d",ans,x1,x2,y1,y2);
	}
	return 0;
}
