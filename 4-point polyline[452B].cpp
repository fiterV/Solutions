#include <stdio.h>
#include <math.h>
#include <set>
#include <vector>
using namespace std;
struct point
{
	int x,y;
	point(){}
	point(int _x,int _y){x=_x;y=_y;}
	bool operator<(const point& b)const
	{
		if (x!=b.x)
			return x<b.x;
		return y<b.y;
	}
};
inline double dist(int x1,int y1,int x2,int y2)
{
	return sqrt((double)((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));
}
int dx[5]={0,1,1,-1,-1},dy[5]={0,1,-1,1,-1},sx[5],sy[5];
int main()
{
	int n,m,i,j,k,l,mi,mj,mk,ml;
	double ans=0.0;
	bool f;
	set<point> sp;
	set<point>::iterator it;
	vector<point> v;
	scanf("%d%d",&n,&m);
	sx[1]=0;sy[1]=0;
	sx[2]=0;sy[2]=m;
	sx[3]=n;sy[3]=0;
	sx[4]=n;sy[4]=m;
	for (k=1;k<=4;k++)
		for (i=0;i<=2;i++)
			for (j=0;j<=2-i;j++)
				sp.insert(point(sx[k]+dx[k]*i,sy[k]+dy[k]*j));
	f=true;
	while (f)
	{
		f=false;
		for (it=sp.begin();it!=sp.end();it++)
			if (it->x<0||it->x>n||it->y<0||it->y>m)
			{
				sp.erase(it);
				f=true;
				break;
			}
	}
	for (it=sp.begin();it!=sp.end();it++)
		v.push_back(*it);
	for (i=0;i<v.size();i++)
		for (j=0;j<v.size();j++)
			for (k=0;k<v.size();k++)
				for (l=0;l<v.size();l++)
					if (i!=j&&i!=k&&i!=l&&j!=k&&j!=l&&k!=l)
					{
						double tmp=dist(v[i].x,v[i].y,v[j].x,v[j].y)+dist(v[j].x,v[j].y,v[k].x,v[k].y)+dist(v[k].x,v[k].y,v[l].x,v[l].y);
						if (tmp>ans)
						{
							ans=tmp;
							mi=i;
							mj=j;
							mk=k;
							ml=l;
						}
					}
	printf("%d %d\n%d %d\n%d %d\n%d %d",v[mi].x,v[mi].y,v[mj].x,v[mj].y,v[mk].x,v[mk].y,v[ml].x,v[ml].y);
	return 0;
}
