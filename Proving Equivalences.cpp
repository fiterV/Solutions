#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
vector<int> mp[20001],ord;
bool vst[20001];
int mk[20001];
void dfs1(int k)
{
    vst[k]=true;
    for (int i=0;i<(int)mp[k].size();i++)
        if (!vst[mp[k][i]])
            dfs1(mp[k][i]);
    ord.push_back(k);
}
void dfs2(int k,int mark)
{
    vst[k]=true;
    mk[k]=mark;
    for (int i=0;i<(int)mp[k].size();i++)
        if (!vst[mp[k][i]])
            dfs2(mp[k][i],mark);
}
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int n,m,t1,t2,mark=0;
        scanf("%d%d",&n,&m);
        for (int i=1;i<=m;i++)
        {
            scanf("%d%d",&t1,&t2);
            mp[t1].push_back(t2);
        }
        memset(vst,false,sizeof(vst));
        ord.clear();
        for (int i=1;i<=n;i++)
            if (!vst[i])
                dfs1(i);
        memset(vst,false,sizeof(vst));
        for (int i=0;i<(int)ord.size();i++)
            if (!vst[ord[i]])
                dfs2(ord[i],++mark);
        if (mark==1)
            printf("0\n");
        else
        {
            vector<int> nin(mark+1,0),nout(mark+1,0);
            for (int i=1;i<=n;i++)
                for (int j=0;j<(int)mp[i].size();j++)
                {
                    int u=mp[i][j];
                    if (mk[i]!=mk[u])
                    {
                        nout[mk[i]]++;
                        nin[mk[u]]++;
                    }
                }
            int in0=0,out0=0;
            for (int i=1;i<=mark;i++)
            {
                if (!nin[i])
                    in0++;
                if (!nout[i])
                    out0++;
            }
            printf("%d\n",in0>out0?in0:out0);
        }
    }
    return 0;
}
