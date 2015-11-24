#include <iostream>
#include <map>
#include <string>
#include <sstream>
using namespace std;
map<string,int> usr;
string inttostr(int c)
{
	string s;
	stringstream ss(s);
	ss<<c;
	return ss.str();
}
int main()
{
	int n,i,j;
	string t;
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>t;
		if (usr.count(t)==0)
		{
			cout<<"OK"<<endl;
			usr[t]=1;
		}
		else
		{
			cout<<t<<inttostr(usr[t])<<endl;
			usr[t]++;
		}
	}
	return 0;
}
