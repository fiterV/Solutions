#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
vector<pair<string,string> > mp;
int main()
{
	string t1,t2;
	int q,i,j;
	bool f;
	cin>>q;
	for (i=0;i<q;i++)
	{
		f=false;
		cin>>t1>>t2;
		for (j=0;j<mp.size();j++)
			if (mp[j].second==t1)
			{
				f=true;
				break;
			}
		if (f)
			mp[j].second=t2;
		else
			mp.push_back(make_pair(t1,t2));
	}
	cout<<mp.size()<<endl;
	for (i=0;i<mp.size();i++)
		cout<<mp[i].first<<" "<<mp[i].second<<endl;
	return 0;
}
