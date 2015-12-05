#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
int mp[9][9],row[9],cul[9],jgg[3][3];
struct point
{
    int x,y;
    inline bool operator<(const point& b)const
    {
        return __builtin_popcount(row[x]|cul[y]|jgg[x/3][y/3])<__builtin_popcount(row[b.x]|cul[b.y]|jgg[b.x/3][b.y/3]);
    }
};
vector<point> uk;
bool dfs(int idx)
{
    if (idx<0)
        return true;
    if (idx%10==8)
        sort(uk.begin(),uk.begin()+idx);
    int x=uk[idx].x,y=uk[idx].y;
    int &r=row[x],&c=cul[y],&j=jgg[x/3][y/3];
    int able=~(r|c|j);
    if (!able)
        return false;
    for (register int i=0;i<9;i++)
        if (able&(1<<i))
        {
            mp[x][y]=i+1;
            r|=1<<i;
            c|=1<<i;
            j|=1<<i;
            if (dfs(idx-1))
                return true;
            r&=~(1<<i);
            c&=~(1<<i);
            j&=~(1<<i);
        }
    return false;
}
int main()
{
    char s[82];
    while (scanf("%s%*c",s)!=-1)
    {
        if (s[0]=='e')
            break;
        uk.clear();
        memset(row,0,sizeof(row));
        memset(cul,0,sizeof(cul));
        memset(jgg,0,sizeof(jgg));
        for (int i=0;i<81;i++)
        {
            mp[i/9][i%9]=s[i]=='.'?0:s[i]-'0';
            if (s[i]!='.')
            {
                int x=i/9,y=i%9,val=s[i]-'0';
                row[x]|=1<<(val-1);
                cul[y]|=1<<(val-1);
                jgg[x/3][y/3]|=1<<(val-1);
            }
            else
                uk.push_back({i/9,i%9});
        }
        sort(uk.begin(),uk.end());
        dfs((int)uk.size()-1);
        for (int i=0;i<9;i++)
            for (int j=0;j<9;j++)
                printf("%d",mp[i][j]);
        printf("\n");
    }
    return 0;
}
