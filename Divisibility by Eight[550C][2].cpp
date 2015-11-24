#include <iostream>
#include <string>
using namespace std;
bool dp[101][8];
pair<int,int> prev[101][8];
string s;
void print(pair<int,int> p)
{
	if (p.first>0)
	{
		print(prev[p.first][p.second]);
		if (prev[p.first][p.second]!=prev[p.first-1][p.second-1])
			cout<<s[p.first-1];
	}
}
int main()
{
	int i,j;
	cin>>s;
	dp[0][0]=true;
	for (i=0;i<s.size();i++)
		for (j=0;j<8;j++)
			if (dp[i][j])
			{
				if (i)
				{
					dp[i+1][j]=true;
					prev[i+1][j]=prev[i][j];
				}
				dp[i+1][(j*10+(s[i]-'0'))%8]=true;
				prev[i+1][(j*10+(s[i]-'0'))%8]=make_pair(i,j);
			}
	for (i=1;i<=s.size();i++)
		if (dp[i][0])
		{
			cout<<"YES"<<endl;
			print(make_pair(i,0));
			return 0;
		}
	cout<<"NO";
	return 0;
}
