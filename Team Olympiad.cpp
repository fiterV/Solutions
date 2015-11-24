#include <iostream>
#include <vector>
using namespace std;
vector<int> v[4];
int main()
{
	int n,i,ans,t;
	cin>>n;
	for (i=0;i<n;i++)
	{
		cin>>t;
		v[t].push_back(i+1);
	}
	ans=min(min(v[1].size(),v[2].size()),v[3].size());
	cout<<ans<<endl;
	for (i=0;i<ans;i++)
		cout<<v[1][i]<<" "<<v[2][i]<<" "<<v[3][i]<<endl;
	return 0;
}
