#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
int pw(int k)
{
	int i,p=1;
	for (i=1;i<=k;i++)
		p*=26;
	return p;
}
int main()
{
	int n,i,j,pr,pc,cr,cc;
	cin>>n;
	string s,t;
	for (i=1;i<=n;i++)
	{
		cin>>s;
		pr=0;
		pc=0;
		cr=0;
		cc=0;
		for (j=0;j<(int)s.size();j++)
			if (s[j]=='R')
				pr=j,cr++;
			else if (s[j]=='C')
				pc=j,cc++;
		for (j=pr+1;j<pc;j++)
			if (s[j]>='A'&&s[j]<='Z')
				pr=1;
		for (j=pc+1;j<=s.size();j++)
			if (s[j]>='A'&&s[j]<='Z')
				pr=1;
		if (cr==1&&cc==1&&pc-pr>1&&pr==0)
		{
			t="";
			int x=atoi(s.substr(1,pc-1).c_str());
			int y=atoi(s.substr(pc+1).c_str());
			while (y!=0)
			{
				
				t=(char)((y-1)%26+'A')+t;
				if (y%26==0)
					y=y/26-1;
				else
					y=y/26;
			}
			cout<<t<<x<<endl;
		}
		else
		{
			int k,nm=0;
			for (j=0;j<(int)s.size();j++)
				if (s[j]>='0'&&s[j]<='9')
				{
					k=j;
					break;
				}
			string t1=s.substr(0,k);
			for (j=(int)t1.size()-1;j>=0;j--)
				nm+=(t1[j]-'A'+1)*pw(t1.size()-j-1);
			int x=atoi(s.substr(k).c_str());
			cout<<"R"<<x<<"C"<<nm<<endl;
		}
	}
}
