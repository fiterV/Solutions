#include <stdio.h>
#include <vector>
using namespace std;
vector<pair<int,int> > mp[10001];
int cnt[10001],pe[10001];
int dfs(int k,int p)
{
    int ret=1,u;
    for (int i=0;i<(int)mp[k].size();i++)
    {
        u=mp[k][i].first;
        if (u!=p)
        {
            ret+=dfs(u,k);
            pe[u]=mp[k][i].second;
        }
    }
    return cnt[k]=ret;
}
int main()
{
    int t,n,i,t1,t2,t3;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);
        for (i=1;i<=n;i++)
            mp[i].clear();
        for (i=1;i<n;i++)
        {
            scanf("%d%d%d",&t1,&t2,&t3);
            t1++;
            t2++;
            mp[t1].push_back(make_pair(t2,t3));
            mp[t2].push_back(make_pair(t1,t3));
        }
        dfs(1,0);
        double ans=0.0;
        int div=n*(n-1)/2;
        for (i=2;i<=n;i++)
            ans+=((double)((long long)pe[i]*cnt[i]*(n-cnt[i])))/div;
        printf("%.10f\n",ans);
    }
    return 0;
}
