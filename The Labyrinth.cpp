#include <stdio.h>
#include <set>
using namespace std;
int n,m,dx[5]={0,0,0,1,-1},dy[5]={0,1,-1,0,0},mark[1001][1001],sm[1000001];
char mp[1001][1002];
void dfs(int x,int y,int cnt)
{
    mark[x][y]=cnt;
    sm[cnt]++;
    for (int i=1;i<=4;i++)
    {
        int ox=x+dx[i],oy=y+dy[i];
        if (ox>0&&ox<=n&&oy>0&&oy<=m&&mp[ox][oy]=='.'&&!mark[ox][oy])
            dfs(ox,oy,cnt);
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        scanf("%s",&mp[i][1]);
    int k=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            if (mp[i][j]=='.'&&!mark[i][j])
                dfs(i,j,++k);
        }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            if (mp[i][j]=='*')
            {
                set<int> st;
                for (int l=1;l<=4;l++)
                {
                    int ox=i+dx[i],oy=j+dy[i];
                    if (ox>0&&ox<=n&&oy>0&&oy<=m&&mp[ox][oy]=='.')
                        st.insert(mark[ox][oy]);
                }
                int ans=1;
                for (set<int>::iterator it=st.begin();it!=st.end();it++)
                    ans+=sm[*it];
                printf("%d",ans%10);
            }
            else
                printf(".");
        }
        printf("\n");
    }
    return 0;
}
