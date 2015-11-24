#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s,t;
	int i;
	bool f=true;
	cin>>s;
	for (i=0;i<s.size();i++)
		if (s[i]!='/')
		{
			t+=s[i];
			f=true;
		}
		else
		{
			if (f)
				t+=s[i];
			f=false;
		}
	if (t[t.size()-1]=='/'&&t.size()>1)
		t=t.substr(0,t.size()-1);
	cout<<t;
	return 0;
}
