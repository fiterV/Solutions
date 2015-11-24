#include <iostream>
#include <string>
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int main()
{
	int i,cnt=0;
	string s;
	cin>>s;
	for (i=0;i<s.size();i++)
		if (s[i]=='0')
			cnt++;
	cout<<min(cnt,s.size()-cnt);
	return 0;
}
