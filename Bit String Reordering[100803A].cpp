#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int bm[16],rlc[16];
int main()
{
    int n,m,ans=1000000000,x;
    vector<int> seq1;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        if (x==1)
            seq1.push_back(i);
    }
    for (int i=1;i<=m;i++)
        scanf("%d",rlc+i);
    for (int sb=0;sb<=1;sb++)
    {
        int bt=sb,k=0;
        vector<int> seq2;
        for (int i=1;i<=m;i++)
        {
            for (int j=1;j<=rlc[i];j++)
            {
                k++;
                if (bt==1)
                    seq2.push_back(k);
            }
            bt^=1;
        }
        if (seq1.size()==seq2.size())
        {
            int cur=0;
            for (int i=0;i<(int)seq1.size();i++)
                cur+=abs(seq1[i]-seq2[i]);
            ans=min(ans,cur);
        }
    }
    printf("%d",ans);
    return 0;
}
