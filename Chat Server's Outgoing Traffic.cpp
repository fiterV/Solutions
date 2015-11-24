#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	int n=0,c=0;
	while (getline(cin,s))
	{
		if (s[0]=='+')
			n++;
		else if (s[0]=='-')
			n--;
		else if (s=="s")      //老师，getline(cin,s)无论怎么输入都会返回true，所以我才加上这一句 
			break;
		else
			c+=((int)s.size()-s.find(':')-1)*n;
	}
	cout<<c<<endl;
	return 0;
}
