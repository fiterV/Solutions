#include <iostream>
#include <string>
using namespace std;
int main()
{
	int i,t=1,ans=0;
	string s;
	cin>>s;
	for (i=1;i<=s.size();i++)
	{
		ans+=(s[s.size()-i]=='4'?1:2)*t;
		t<<=1;
	}
	cout<<ans;
	return 0;
}
