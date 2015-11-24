#include <iostream>
using namespace std;
int x[3001],y[3001];
bool b[2001][2001];
int main()
{
	int n,i,j,cnt=0;
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i];
		x[i]+=1000;
		y[i]+=1000;
		b[x[i]][y[i]]=true;
	}
	for (i=1;i<n;i++)
		for (j=i+1;j<=n;j++)
			if ((x[i]+x[j])%2==0&&(y[i]+y[j])%2==0&&b[(x[i]+x[j])/2][(y[i]+y[j])/2]) cnt++;
	cout<<cnt;
	return 0;
}
