#include <iostream>
#include <string>
using namespace std;
inline int min(int a,int b)
{
	return a<b?a:b;
}
int dp[1001][1001];
string s1,s2;
int main()
{
	int i,j,l1,l2;
	while (cin>>l1>>s1>>l2>>s2)
	{
		dp[0][0]=0;
		for (i=1;i<=l1;i++)
			dp[i][0]=i;
		for (i=1;i<=l2;i++)
			dp[0][i]=i;
		for (i=1;i<=l1;i++)
			for (j=1;j<=l2;j++)
				dp[i][j]=min(1+dp[i-1][j],min(1+dp[i][j-1],(s1[i-1]==s2[j-1]?0:1)+dp[i-1][j-1]));
		cout<<dp[l1][l2]<<endl;
	}
	return 0;
}
