#include <iostream>
#include <string>
using namespace std;
int main()
{
	string x;
	int i;
	cin>>x;
	for (i=0;i<x.size();i++)
		if (x[i]>='5'&&x[i]<'9'||x[i]=='9'&&i!=0)
			x[i]=9-(x[i]-'0')+'0';
	while (x[0]=='0'&&x.size()>1)
		x=x.substr(1);
	cout<<x;
	return 0;
}

