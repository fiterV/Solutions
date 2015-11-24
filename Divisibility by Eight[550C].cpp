#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	int i,j,k;
	cin>>s;
	for (i=0;i<(int)s.size();i++)
		if (((s[i]-'0')&7)==0)
		{
			cout<<"YES"<<endl<<s[i]-'0';
			return 0;
		}
	for (i=s.size()-1;i>=1;i--)
		for (j=i-1;j>=0;j--)
			if ((((s[j]-'0')*10+s[i]-'0')&7)==0)
			{
				cout<<"YES"<<endl<<(s[j]-'0')*10+s[i]-'0';
				return 0;
			}
	for (i=s.size()-1;i>=2;i--)
		if (((s[i]-'0')&1)^1)
			for (j=i-1;j>=1;j--)
				if ((((s[j]-'0')*10+s[i]-'0')&3)==0)
					for (k=j-1;k>=0;k--)
						if ((((s[k]-'0')*100+(s[j]-'0')*10+s[i]-'0')&7)==0)
						{
							cout<<"YES"<<endl<<(s[k]-'0')*100+(s[j]-'0')*10+s[i]-'0';
							return 0;
						}
	cout<<"NO";
	return 0;
}
