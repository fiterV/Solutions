#include <iostream>
#include <string>
using namespace std;
string nm[9]={"","vaporeon","jolteon","flareon","espeon","umbreon","leafeon","glaceon","sylveon"};
char toupp(char a)
{
	if (a>='a'&&a<='z')
		return a-('a'-'A');
	else
		return a;
}
int main()
{
	int n,i,j;
	string s;
	cin>>n>>s;
	for (i=1;i<=8;i++)
		if (s.size()==nm[i].size())
		{
			for (j=0;j<s.size();j++)
				if (toupp(s[j])!=toupp(nm[i][j])&&s[j]!='.')
					break;
			if (j==s.size())
			{
				cout<<nm[i];
				return 0;
			}
		}
}
