#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
using namespace std;
struct point
{
	int x,y;
};
int row[10],cul[10],jgg[4][4],mp[10][10],mod[10]={0,1,1,1,2,2,2,3,3,3},log2[1<<11];
point pn[82];
inline void st(int x,int y,int t)
{
	row[x]|=1<<(t-1);
	cul[y]|=1<<(t-1);
	jgg[mod[x]][mod[y]]|=1<<(t-1);
}
inline bool cmp(const point& a,const point& b)
{
	int enable1=row[a.x]|cul[a.y]|jgg[mod[a.x]][mod[a.y]];
	int enable2=row[b.x]|cul[b.y]|jgg[mod[b.x]][mod[b.y]];
	int cnt1=0,cnt2=0;
	for (;enable1;enable1-=(enable1&(-enable1)),cnt1++);
	for (;enable2;enable2-=(enable2&(-enable2)),cnt2++);
	return cnt1<cnt2;
}
bool dfs(int cn)
{
	if (cn<=0)
		return true;
	int i,x=pn[cn].x,y=pn[cn].y;
	int &r=row[x],&c=cul[y],&j=jgg[mod[x]][mod[y]],&m=mp[x][y];
	int tr=r,tc=c,tj=j,tmp;
	if (cn%10==8)
		sort(pn+1,pn+cn,cmp);
	for (i=(~(r|c|j))&((1<<9)-1);i;i-=(i&(-i)))
	{
		tmp=i&(-i);
		m=log2[tmp]+1;
		r=tr|tmp;
		c=tc|tmp;
		j=tj|tmp;
		if (dfs(cn-1))
			return true;
	}
	r=tr;
	c=tc;
	j=tj;
	return false;
}
int main()
{
	int i,j,cn;
	char t;
	string n;
	freopen("in\\poj 3074.in","r",stdin);
	for (i=0;i<=10;i++)
		log2[1<<i]=i;
	for (;;)
	{
		cin>>n;
		if (n[0]=='e')
			break;
		memset(row,0,sizeof(row));
		memset(cul,0,sizeof(cul));
		memset(jgg,0,sizeof(jgg));
		memset(mp,0,sizeof(mp));
		cn=0;
		for (i=0;i<(int)n.size();i++)
		{
			t=n[i];
			if (t=='.')
				t='0';
			mp[i/9+1][i%9+1]=t-'0';
			if (t!='0')
				st(i/9+1,i%9+1,t-'0');
			else
			{
				pn[++cn].x=i/9+1;
				pn[cn].y=i%9+1;
			}
		}
		sort(pn+1,pn+cn+1,cmp);
		dfs(cn);
		for (i=1;i<=9;i++)
			for (j=1;j<=9;j++)
				cout<<mp[i][j];
		cout<<endl;
	}
	return 0;
}
