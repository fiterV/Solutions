#include <stdio.h>
#include <string.h>
#include <algorithm>
#define maxn 2008
using namespace std;
int sum,len,tot;
char str[maxn],ans[maxn];
void Print(int p,int q)
{
	int l=0,i;
	for (i=0;i<len;i++)
		if (i!=p&&i!=q)
			ans[l++]=str[i];
	while (str[l-1]=='0'&&l>1)
		l--;
	if (ans[0]!='0')
	{
		for (i=0;i<l;i++)
			if (ans[i]=='5')
			{
				swap(ans[0],ans[i]);
				break;
			}
		if (l>1)
			sort(ans+1,ans+l);
	}
	for (i=l-1;i>=0;i--)
		printf("%c",ans[i]);
}
int main()
{
	int i,j;
	scanf("%s",str);
	len=strlen(str);
	sort(str,str+len);
	for (i=0;i<len;i++)
		sum+=str[i]-'0';
	if (str[0]!='0')
	{
		tot=0;
		for (i=0;i<len;i++)
			if (str[i]=='5')
				tot++;
		if (!tot)
		{
			printf("impossible");
			return 0;
		}
	}
	if (sum%3==0)
	{
		Print(len,len);
		return 0;
	}
	if (sum%3==1)
	{
		for (i=0;i<len;i++)
		if ((str[i]-'0')%3==1)
		{
			Print(i,len);
			return 0;
		}
		for (i=1;i<len;i++)
			if ((str[i]-'0')%3==2)
			for (j=0;j<i;j++)
				if ((str[j]-'0')%3==2)
				{
					int tmp=0;
					if (str[i]=='5') tmp++;
					if (str[j]=='5') tmp++;
					if (str[0]=='0'||tmp<tot)
					{
						Print(i,j);
						return 0;
					}
				}
		printf("impossible");
		return 0;
	}
	if (sum%3==2)
	{
		for (i=0;i<len;i++)
			if ((str[i]-'0')%3==2)
				if (str[0]=='0'||str[i]!='5'||tot>1){
				Print(i,len);
				return 0;
			}
		for (i=1;i<len;i++)
			if ((str[i]-'0')%3==1)
				for (j=0;j<i;j++)
					if ((str[j]-'0')%3==1)
					{
						Print(i,j);
						return 0;
					}
		printf("impossible");
		return 0;
	}
}
