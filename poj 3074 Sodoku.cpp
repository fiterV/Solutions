#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
struct point
{
	int x,y;
};
int row[10],cul[10],jgg[4][4];
int mp[10][10],mod[10]={0,1,1,1,2,2,2,3,3,3};
point pn[82];
inline void st(int x,int y,int t)
{
	row[x]|=1<<(t-1);
	cul[y]|=1<<(t-1);
	jgg[mod[x]][mod[y]]|=1<<(t-1);
}
inline bool cmp(const point& a,const point& b)
{
	int xa=a.x,ya=a.y,xb=b.x,yb=b.y;
    int enable1=row[xa]|cul[ya]|jgg[mod[xa]][mod[ya]];
    int enable2=row[xb]|cul[yb]|jgg[mod[xb]][mod[yb]];
    int cnt1=0,cnt2=0;
    for (int i=0;i<9;i++)
    {
        if (enable1&(1<<i))
                cnt1++;
        if (enable2&(1<<i))
                cnt2++;
    }
    return cnt1<cnt2;
}
bool dfs(int cn)
{
	if (cn<=0)
		return true;
	int i,cx=pn[cn].x,cy=pn[cn].y;
	int& r=row[cx],c=cul[cy],j=jgg[mod[cx]][mod[cy]];
	int enable=~(r|c|j),tmp=1,tr=r,tc=c,tj=j;
	if (cn%10==5)
		sort(pn+1,pn+cn,cmp);
	for (i=1;i<=9;i++)
	{
		if (enable&tmp)
		{
			mp[cx][cy]=i;
			r=tr|tmp;
			c=tc|tmp;
			j=tj|tmp;
			if (dfs(cn-1))
				return true;
		}
		tmp<<=1;
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
	for (;;)
	{
		cin>>n;
		if (n=="end")
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
			if (t!='0')
			{
				mp[i/9+1][i%9+1]=t-'0';
				st(i/9+1,i%9+1,t-'0');
			}
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
