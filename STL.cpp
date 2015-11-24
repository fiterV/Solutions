#include <iostream>
#include <string>
using namespace std;
string z,s;
bool t;
void F()
{
	if (cin>>s)
	{
		z+=s;
		if (s=="pair")
		{
			z+="<";
			F();
			z+=",";
			F();
			z+=">";
		}
		else if (s=="s")
			return;
	}
	else
		t=true;
}
int main()
{
	//cin>>s;
	F();
	if (t||cin>>s)
		cout<<"Error occurred";
	else
		puts(z.c_str());
	return 0;
}
