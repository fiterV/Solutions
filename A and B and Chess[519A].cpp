#include <iostream>
#include <map>
using namespace std;
map<char,int> mp;
int main()
{
	int i,j,wht=0,blk=0;
	char t;
	bool f;
	mp['Q']=9;
	mp['R']=5;
	mp['B']=3;
	mp['N']=3;
	mp['P']=1;
	mp['.']=0;
	for (i=1;i<=8;i++)
		for (j=1;j<=8;j++)
		{
			f=false;
			cin>>t;
			if (t>='a'&&t<='z')
			{
				t-='a'-'A';
				f=true;
			}
			if (f)
				blk+=mp[t];
			else
				wht+=mp[t];
		}
	if (blk>wht)
		cout<<"Black";
	else if (blk==wht)
		cout<<"Draw";
	else
		cout<<"White";
	return 0;
}
