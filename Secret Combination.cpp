#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n,i,j;
	cin>>n;
	string k,r,min;
	cin>>k;
	r=k;
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			r[j]=k[(j+i)%n]-k[i]+'0';
			if (r[j]<'0') r[j]+=10;
		}
		if (min>r&&min!=""||min=="") min=r;
	}
	cout<<min;
	return 0;
}
