#include <iostream>
using namespace std;
int a[51],b[51],c[51],d[51];
bool x[1005],z[1005];
int main()
{
	int p,q,l,r,i,j,t,cnt=0;
	cin>>p>>q>>l>>r;
	for (i=1;i<=p;i++)
	{
		cin>>a[i]>>b[i];
		for (j=a[i];j<=b[i];j++)
			x[j]=true;
	}
	for (i=1;i<=q;i++)
		cin>>c[i]>>d[i];
	for (t=l;t<=r;t++)
	{
		for (i=1;i<=1000;i++)
			z[i]=false;
		for (i=1;i<=q;i++)
			for (j=c[i];j<=d[i];j++)
				z[j+t]=true;
		for (i=1;i<=1000;i++)
			if (x[i]&&z[i])
			{
				cnt++;
				break;
			}
	}
	cout<<cnt;
	return 0;
}
