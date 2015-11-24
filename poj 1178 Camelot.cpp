#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
#define min(a,b) (a<b?a:b)
using namespace std;
struct mat
{
	vector<vector<int> > mn;
	int x,y;
};
vector<mat> mk;
mat mi,tmp;
bool vst[9][9];
const int dx[9]={0,-2,-2,-1,1,2,2,1,-1},dy[9]={0,-1,1,2,2,1,-1,-2,-2};
void cal(mat& mt,bool king)
{
	pair<int,int> f;
	queue<pair<int,int> > q;
	int i,j,oi,oj;
	q.push(make_pair(mt.x,mt.y));
	memset(vst,false,sizeof(vst));
	mt.mn=vector<vector<int> >(9,vector<int>(9,-1));
	vst[mt.x][mt.y]=true;
	mt.mn[mt.x][mt.y]=0;
	while (!q.empty())
	{
		f=q.front();
		q.pop();
		printf("%d %d ",f.first,f.second);
		if (king)
		{
			for (i=-1;i<=1;i++)
				for (j=-1;j<=1;j++)
					if (i||j)
					{
						oi=f.first+i;
						oj=f.second+j;
						if (oi>0&&oj>0&&oi<=8&&oj<=8&&!vst[oi][oj])
						{
							vst[oi][oj]=true;
							mt.mn[oi][oj]=mt.mn[f.first][f.second]+1;
							q.push(make_pair(oi,oj));
						}
					}
		}
		else
		{
			for (i=1;i<=8;i++)
			{
				oi=f.first+dx[i];
				oj=f.second+dy[i];
				if (oi>0&&oi<=8&&oj>0&&oj<=8&&!vst[oi][oj])
				{
					vst[oi][oj]=true;
					mt.mn[oi][oj]=mt.mn[f.first][f.second]+1;
					q.push(make_pair(oi,oj));
				}
			}
		}
	}
	printf("\n\n\n");
}
int main()
{
	char c;
	int r,i,j,k,mn,ans=1000000000;
	int n;
	scanf("%d",&n);
	scanf("%c%d",&c,&r);
	mi.x=c-'A'+1;
	mi.y=r;
	cal(mi,true);
	while (--n)
	{
		scanf("%c%d",&c,&r);
		tmp.x=c-'A'+1;
		tmp.y=r;
		mk.push_back(tmp);
		cal(mk.back(),false);
	}
	for (i=1;i<=8;i++)
		for (j=1;j<=8;j++)
		{
			if (mi.mn[i][j]==-1)
				continue;
			for (k=0;k<(int)mk.size();k++)
				if (mk[k].mn[i][j]==-1)
					break;
			if (k!=(int)mk.size())
				continue;
			mn=mi.mn[i][j];
			for (k=0;k<(int)mk.size();k++)
				mn+=mk[k].mn[i][j];
			ans=min(ans,mn);
		}
	printf("%d",ans);
	return 0;
}
