#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int s[100]={25,18,15,12,10,8,6,4,2,1};
struct P
{
	string name;
	int s;
	int w;
	vector<int> rank;
};
P p[1010];
bool cmp1(const P& a,const P& b)
{
	int i=0;
	if(a.s==b.s)
	{
		while (true)
		{
			if(a.rank[i]==b.rank[i])
			{
				i++;
				if(a.rank.size()==i)
					return false;
				else if(b.rank.size()==i)
					return true;
			}
			else
				return a.rank[i]<b.rank[i];
		}
	}
	return a.s>b.s;
}
bool cmp2(const P& a,const P& b)
{
	if(a.w!=b.w)
		return a.w>b.w;
	else
		return cmp1(a,b);
}
int main()
{
	int n,k=0,i,j,h;
	set<string> str;
	set<string>::iterator ps;
	cin>>n;
	for (i=0;i<n;i++)
	{
		int m;
		string name;
		cin>>m;
		for (j=0;j<m;j++)
		{
			cin>>name;
			if (str.find(name)==str.end())
			{
				str.insert(name);
				p[k].name=name;
				p[k].s=s[j];
				if (j==0)
					p[k].w++;
				p[k].rank.push_back(j);
				k++;
			}
			else
				for (h=0;h<k;h++)
					if(name==p[h].name)
					{
						p[h].s+=s[j];
						if(j==0)
							p[h].w++;
						p[h].rank.push_back(j);
						break;
					}
		}
	}
	for(i=0;i<k;i++ )
		sort(p[i].rank.begin(),p[i].rank.end());
	sort(p,p+k,cmp1);
	cout<<p[0].name<<endl;
	sort(p,p+k,cmp2);
	cout<<p[0].name<<endl;
	return 0;
}
