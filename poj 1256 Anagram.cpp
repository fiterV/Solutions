#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
inline char tolow(char a)
{
	return a<='Z'?a+'a'-'A':a;
}
bool cmp(char a,char b)
{
	if (tolow(a)!=tolow(b))
		return tolow(a)<tolow(b);
	else
		return (a<='Z')>(b<='Z');
}
int main()
{
	int n,i;
	string s;
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>s;
		sort(s.begin(),s.end(),cmp);
		do
			cout<<s<<endl;
		while (next_permutation(s.begin(),s.end(),cmp));
	}
	return 0;
}
