#include <iostream>
using namespace std;
int a[101],ans[101];
int main()
{
	int n,i,cnt1=0,cnt2=0,cnt3=0,idx=0;
	bool f=false;
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>a[i];
		if (a[i]==0)
		{
			ans[i]=3;
			cnt3++;
		}
		else if (a[i]>0||a[i]<0&&f)
		{
			ans[i]=2;
			cnt2++;
			if (a[i]<0)
			{
				cnt1++;
				idx=i;
			}
		}
		else
		{
			ans[i]=1;
			f=true;
		}
	}
	if (cnt1%2)
	{
		ans[idx]=3;
		cnt2--;
		cnt3++;
	}
	cout<<1<<" ";
	for (i=1;i<=n;i++)
		if (ans[i]==1)
			cout<<a[i]<<" ";
	cout<<endl<<cnt2<<" ";
	for (i=1;i<=n;i++)
		if (ans[i]==2)
			cout<<a[i]<<" ";
	cout<<endl<<cnt3<<" ";
	for (i=1;i<=n;i++)
		if (ans[i]==3)
			cout<<a[i]<<" ";
	return 0;
}
