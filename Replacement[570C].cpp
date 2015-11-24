#include <iostream>
#include <string>
#include <set>
using namespace std;
string s;
set<int> pos;
int main()
{
	int n,m,i,x;
	char c;
	cin>>n>>m>>s;
	for (i=1;i<n;i++)
		if (s[i-1]=='.'&&s[i]=='.')
			pos.insert(i);
	while (m--)
	{
		cin>>x>>c;
		if (x>1&&pos.count(x-1)&&c!='.')
			pos.erase(x-1);
		if (x<n&&pos.count(x)&&c!='.')
			pos.erase(x);
		if (x>1&&!pos.count(x-1)&&s[x-2]=='.'&&c=='.')
			pos.insert(x-1);
		if (x<n&&!pos.count(x)&&c=='.'&&s[x]=='.')
			pos.insert(x);
		s[x-1]=c;
		cout<<pos.size()<<endl;
	}
	return 0;
}
