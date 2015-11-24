#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
map<string,string> src,gt;
vector<string> ans;
int main()
{
	int n,i;
	string s1,s2;
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>s1>>s2;
		if (!src[s1].empty())
		{
			src[s2]=src[s1];
			gt[src[s1]]=s2;
		}
		else
		{
			ans.push_back(s1);
			src[s2]=s1;
			gt[s1]=s2;
		}
	}
	cout<<ans.size()<<endl;
	for (i=0;i<ans.size();i++)
		cout<<ans[i]<<" "<<gt[ans[i]]<<endl;
	return 0;
}
