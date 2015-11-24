#include <iostream>
using namespace std;
int n,k,p[1001],np;
bool a[1001];
int main()
{
	cin>>n>>k;
	int i,j,cnt=0;
	a[1]=true;
	for (i=2;i<=n;i++)
		if (!a[i])
			for (j=2;j<=n/i;j++)
				a[i*j]=true;
	for (i=1;i<=n;i++)
		if (!a[i]) p[++np]=i;
	for (i=1;i<=np;i++)
		for (j=1;j<i;j++)
			if (p[j]+p[j+1]+1==p[i]){cnt++;break;}
	if (cnt>=k) cout<<"YES"; else cout<<"NO";
    return 0;
}
