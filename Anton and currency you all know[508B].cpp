#include <iostream>
#include <string>
using namespace std;
int main()
{
	string n,t;
	char l;
	int i,k;
	cin>>n;
	l=n[n.size()-1];
	for (i=0;i<n.size();i++)
		if ((n[i]-'0')%2==0&&n[i]<l)
		{
			k=i;
			break;
		}
	if (i==n.size())
		for (i=n.size()-1;i>=0;i--)
			if ((n[i]-'0')%2==0)
			{
				k=i;
				break;
			}
	if (i==-1)
		cout<<-1;
	else
	{
		t=n.substr(0,k)+l+n.substr(k+1,n.size()-k-2)+n[k];
		cout<<t;
	}
	return 0;
}

