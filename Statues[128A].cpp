#include <stdio.h>
#include <vector>
#include <set>
using namespace std;
struct state
{
    int x,y;
    vector<pair<int,int> > st;
    bool operator<(const state& b)const
    {
        if (x!=b.x)
            return x<b.x;
        if (y!=b.y)
            return y<b.y;
        if (st.size()!=b.st.size())
            return st.size()<b.st.size();
        for (int i=0;i<(int)st.size();i++)
            if (st[i]!=b.st[i])
                return st[i]<b.st[i];
        return false;
    }
};
char mp[9][9];
const int dx[9]={1,1,-1,-1,1,-1,0,0,0},dy[9]={1,-1,1,-1,0,0,1,-1,0};
set<state> vst;
bool dfs(state st)
{
    vst.insert(st);
    state tmp;
    for (vector<pair<int,int> >::iterator it=st.st.begin();it!=st.st.end();it++)
        if ((*it).first!=8)
            tmp.st.push_back(make_pair((*it).first+1,(*it).second));
    for (int i=0;i<9;i++)
    {
        int ox=st.x+dx[i],oy=st.y+dy[i];
        if (ox==1&&oy==8)
            return true;
        if (ox>0&&ox<=8&&oy>0&&oy<=8)
        {
            int j;
            for (j=0;j<(int)st.st.size();j++)
            {
                pair<int,int> pos=st.st[j];
                if ((ox==pos.first&&oy==pos.second)||(oy==pos.second&&ox==pos.first+1))
                    break;
            }
            if (j==(int)st.st.size())
            {
                tmp.x=ox;
                tmp.y=oy;
                if (!vst.count(tmp)&&dfs(tmp))
                    return true;
            }
        }
    }
    return false;
}
int main()
{
    for (int i=1;i<=8;i++)
        scanf("%s",mp[i]+1);
    state init;
    for (int i=1;i<=8;i++)
        for (int j=1;j<=8;j++)
            if (mp[i][j]=='M')
            {
                init.x=i;
                init.y=j;
            }
            else if (mp[i][j]=='S')
                init.st.push_back(make_pair(i,j));
    printf("%s",dfs(init)?"WIN":"LOSE");
    return 0;
}
