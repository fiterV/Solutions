#include <stdio.h>
#include <bitset>
using namespace std;
bool mp[200][200];
int n;
bitset<200> arr[200];
void calculate()
{
    int cnt=0;
    for (int i=n-1;i>=0;i--)
    {
        arr[i].reset();
        arr[i].set(i);
        for (int j=i+1;j<n;j++)
            if (mp[i][j])
                arr[i]|=arr[j];
        cnt+=arr[i].count();
    }
    printf("%d\n",cnt-n);
}
int main()
{
    int m,t1,t2,q;
    freopen("settling.in","r",stdin);
    freopen("settling.out","w",stdout);
    scanf("%d%d",&n,&m);
    while (m--)
    {
        scanf("%d%d",&t1,&t2);
        mp[t1-1][t2-1]=true;
    }
    calculate();
    scanf("%d%*c",&q);
    while (q--)
    {
        char c;
        scanf("%c%d%d%*c",&c,&t1,&t2);
        t1--;
        t2--;
        if (c=='?')
            printf("%s\n",arr[t1].test(t2)?"YES":"NO");
        else
        {
            mp[t1][t2]^=1;
            calculate();
        }
    }
    return 0;
}
