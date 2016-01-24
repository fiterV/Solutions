#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;
#define INF 1000000000
char mp[1001][1002];
bool vst[1001][1001][3];
int dist[1001][1001][3],dx[5]={0,0,0,1,-1},dy[5]={0,1,-1,0,0},n,m;
vector<pair<int,int> > states[3];
struct node
{
    int x,y,mk;
    node(int _x,int _y,int _mk):x(_x),y(_y),mk(_mk)
    {
    }
};
int get_distance(int a,int b)
{
    queue<node> q;
    for (int i=0;i<(int)states[a].size();i++)
    {
        q.push(node(states[a][i].first,states[a][i].second,a));
        dist[states[a][i].first][states[a][i].second][a]=0;
    }
    while (!q.empty())
    {
        node f=q.front();
        q.pop();
        for (int i=1;i<=4;i++)
        {
            int ox=f.x+dx[i],oy=f.y+dy[i];
            if (ox>0&&ox<=n&&oy>0&&oy<=m&&mp[ox][oy]!='#'&&dist[ox][oy][a]==-1)
            {
                dist[ox][oy][a]=dist[f.x][f.y][a]+1;
                if (mp[ox][oy]=='0'+b+1)
                    return dist[ox][oy][a];
                q.push(node(ox,oy,a));
            }
        }
    }
    return INF;
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        scanf("%s",&mp[i][1]);
    queue<node> q;
    memset(dist,-1,sizeof(dist));
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (mp[i][j]!='.'&&mp[i][j]!='#')
            {
                states[mp[i][j]-'0'-1].push_back(pair<int,int>(i,j));
                q.push(node(i,j,mp[i][j]-'0'-1));
                dist[i][j][mp[i][j]-'0'-1]=0;
            }
    while (!q.empty())
    {
        node f=q.front();
        q.pop();
        for (int i=1;i<=4;i++)
        {
            int ox=f.x+dx[i],oy=f.y+dy[i];
            if (ox>0&&ox<=n&&oy>0&&oy<=m&&mp[ox][oy]=='.'&&!vst[ox][oy][f.mk])
            {
                vst[ox][oy][f.mk]=true;
                dist[ox][oy][f.mk]=dist[f.x][f.y][f.mk]+1;
                q.push(node(ox,oy,f.mk));
            }
        }
    }
    int ans=INF;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (mp[i][j]=='.'&&dist[i][j][0]!=-1&&dist[i][j][1]!=-1&&dist[i][j][2]!=-1)
                ans=min(ans,dist[i][j][0]+dist[i][j][1]+dist[i][j][2]-2);
    memset(dist,-1,sizeof(dist));
    int sdist[3]={get_distance(1,2),get_distance(2,0),get_distance(0,1)};
    if ((sdist[0]==INF)+(sdist[1]==INF)+(sdist[2]==INF)<=1)
    {
        ans=min(ans,sdist[0]+sdist[1]-2);
        ans=min(ans,sdist[0]+sdist[2]-2);
        ans=min(ans,sdist[1]+sdist[2]-2);
    }
    printf("%d",ans==INF?-1:ans);
    return 0;
}
