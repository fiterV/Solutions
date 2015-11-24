#include <iostream>
#include <string>
using namespace std;
bool ishuiwen(string s)
{
	for (int i=0;i<s.size();i++)
		if (s[i]!=s[s.size()-i-1]) return false;
	return true;
}
int main()
{
	string s,t;
	cin>>s;
	int i;
	char j;
	for (i=1;i<=s.size()+1;i++)
	{
		for (j='a';j<='z';j++)
		{
			if (i==1)
				t=j+s;
			else if (i==s.size()+1)
				t=s+j;
			else
			{
				t=s.substr(0,i-1)+j+s.substr(i-1);
			}
			if (ishuiwen(t))
			{
				cout<<t<<endl;
				return 0;
			}
		}
	}
	cout<<"NA";
	return 0;
}
