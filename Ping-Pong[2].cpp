#include <iostream>
#define cnrch(i,j) a[i].s>a[j].s&&a[i].s<a[j].e||a[i].e>a[j].s&&a[i].e<a[j].e
using namespace std;
struct interval
{
	int s,e;
};
interval a[101];
bool vst[101],ans[101];
int sm;
void src(int k)
{
	int i;
	vst[k]=true;
	for (i=1;i<=sm;i++)
		if (cnrch(k,i)&&!vst[i])
			src(i);
}
int main()
{
	int n,flg,x,y,i,san=0,j;
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>flg>>x>>y;
		if (flg==1)
		{
			sm++;
			a[sm].s=x;
			a[sm].e=y;
		}
		else
		{
			san++;
			for (j=1;j<=100;j++)
				vst[j]=false;
			src(x);
			if (vst[y])
				ans[san]=true;
			else
				ans[san]=false;
		}
	}
	for (i=1;i<=san;i++)
	{
		if (ans[i])
			cout<<"YES";
		else
			cout<<"NO";
		cout<<endl;
	}
	return 0;
}
