#include <iostream>
#include <string>
using namespace std;
string s1,s2;
string mer(string x)
{
	int l=x.size();
	if (l&1)
		return x;
	string le=mer(x.substr(0,l>>1)),ri=mer(x.substr(l>>1));
	return le<ri?(le+ri):(ri+le);
}
int main()
{
	cin>>s1>>s2;
	if (mer(s1)==mer(s2))
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}
