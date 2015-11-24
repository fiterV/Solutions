#include <iostream>
#include <algorithm>
using namespace std;
int pos[26][10001],v[26];
int main()
{
    string x,y;
    ios::sync_with_stdio(false);
    cin>>x>>y;
    int a,b=(int)y.size(),idx=0,ans=0;
    for (a=0;a<(int)x.size();a++)
    {
        int t=x[a]-'a';
        pos[t][v[t]++]=a;
    }
    for (int i=0;i<b;i++)
    {
        int t=y[i]-'a';
        if (!v[t])
        {
            cout<<-1<<endl;
            return 0;
        }
        if (pos[t][v[t]-1]<idx)
        {
            idx=pos[t][0]+1;
            ans++;
        }
        else
        {
            idx=*lower_bound(pos[t],pos[t]+v[t],idx)+1;
            if (idx==a)
            {
                idx=0;
                ans++;
            }
        }
    }
    cout<<ans+(idx?1:0);
    return 0;
}
