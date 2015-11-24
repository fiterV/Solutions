#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	char x1,x2;
	int y1,y2,mvx,mvy,i;
	string s;
	cin>>x1>>y1>>x2>>y2;
	mvx=x2-x1;
	mvy=y2-y1;
	if (mvx>=0)
		s+='R';
	else
		s+='L';
	if (mvy>=0)
		s+='U';
	else
		s+='D';
	cout<<min(abs(mvx),abs(mvy))+abs(abs(mvx)-abs(mvy))<<endl;
	for (i=1;i<=min(abs(mvx),abs(mvy));i++)
		cout<<s<<endl;
	s="";
	if (mvx+mvy>=0&&mvx>=mvy)
		s="R";
	else if (mvx+mvy>=0&&mvx<mvy)
		s="U";
	else if (mvx+mvy<0&&mvx>=mvy)
		s="D";
	else
		s="L";
	for (i=1;i<=abs(abs(mvx)-abs(mvy));i++)
		cout<<s<<endl;
	return 0;
}

