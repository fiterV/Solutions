#include <iostream>
#include <iomanip>
#define EPS 0.0000001
using namespace std;
const double PI=3.1415926535897932;
double rd[10001];
int main()
{
	int z,n,f,i;
	long long cnt;
	double l,r,m;
	cin>>z;
	cout<<fixed<<setprecision(5);
	while (z--)
	{
		cin>>n>>f;
		for (i=1;i<=n;i++)
		{
			cin>>rd[i];
			rd[i]=rd[i]*rd[i]*PI;
		}
		l=0.0;
		r=1000000000.0;
		while (r-l>EPS)
		{
			m=(l+r)/2;
			cnt=0;
			for (i=1;i<=n;i++)
			{
				cnt+=(long long)(rd[i]/m);
				if (cnt>=f+1)
					break;
			}
			if (cnt>=f+1)
				l=m;
			else
				r=m;
		}
		cout<<l<<endl;
	}
	return 0;
}
