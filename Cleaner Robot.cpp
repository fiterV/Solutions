#include <iostream>
using namespace std;
char mp[11][11];
bool vst[11][11][4];
const int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
int w,h;
void dfs(int x,int y,int dir)
{
    vst[x][y][dir]=true;
    for (int i=dir,tmp=1;tmp<=4;i=(i+1)%4,tmp++)
    {
        int ox=x+dx[i],oy=y+dy[i];
        if (ox>0&&ox<=w&&oy>0&&oy<=h&&mp[ox][oy]=='.')
        {
            if (!vst[ox][oy][i])
                dfs(ox,oy,i);
            return;
        }
    }
}
int main()
{
    int i,j,ix,iy,idir;
    cin>>w>>h;
    for (i=1;i<=w;i++)
        for (j=1;j<=h;j++)
        {
            cin>>mp[i][j];
            if (mp[i][j]=='U')
                idir=0;
            else if (mp[i][j]=='R')
                idir=1;
            else if (mp[i][j]=='D')
                idir=2;
            else if (mp[i][j]=='L')
                idir=3;
            if (mp[i][j]!='.'&&mp[i][j]!='*')
            {
                ix=i;
                iy=j;
                mp[i][j]='.';
            }
        }
    dfs(ix,iy,idir);
    int ans=0;
    for (i=1;i<=w;i++)
        for (j=1;j<=h;j++)
            ans+=vst[i][j][0]||vst[i][j][1]||vst[i][j][2]||vst[i][j][3];
    cout<<ans;
    return 0;
}
