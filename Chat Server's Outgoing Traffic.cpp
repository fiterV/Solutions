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
		else if (s=="s")      //��ʦ��getline(cin,s)������ô���붼�᷵��true�������Ҳż�����һ�� 
			break;
		else
			c+=((int)s.size()-s.find(':')-1)*n;
	}
	cout<<c<<endl;
	return 0;
}
