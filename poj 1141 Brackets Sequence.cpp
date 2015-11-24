#include <iostream>
#include <string>
using namespace std;
int dp[101][101],prev[101][101];
string s;
void print(int i,int j)
{
	if (i==j)
		return;
	else if (j==i+1)
	{
		if (s[i]=='['||s[i]==']')
			cout<<"[]";
		else
			cout<<"()";
	}
	else if (prev[i][j]==-1)
	{
		cout<<s[i];
		print(i+1,j-1);
		cout<<s[j-1];
	}
	else
	{
		print(i,prev[i][j]);
		print(prev[i][j],j);
	}
}
int main()
{
	int i,j,k,l,md;
	while (cin>>s)
	{
		for (i=0;i<s.size();i++)
			dp[i][i+1]=1;
		for (l=2;l<=s.size();l++)
			for (i=0;i+l<=s.size();i++)
			{
				dp[i][i+l]=1000000000;
				for (k=i+1;k<i+l;k++)
					if (dp[i][k]+dp[k][i+l]<dp[i][i+l])
					{
						dp[i][i+l]=dp[i][k]+dp[k][i+l];
						prev[i][i+l]=k;
					}
				if ((s[i]=='['&&s[i+l-1]==']'||s[i]=='('&&s[i+l-1]==')')&&dp[i+1][i+l-1]<dp[i][i+l])
				{
					dp[i][i+l]=dp[i+1][i+l-1];
					prev[i][i+l]=-1;
				}
			}
		print(0,s.size());
		cout<<endl;
	}
	return 0;
}
