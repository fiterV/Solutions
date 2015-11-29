#include <stdio.h>
#include <set>
using namespace std;
int a[100001];
int main()
{
    int n,l=1,ans=0;
    multiset<int> seq;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",a+i);
    for (int i=1;i<=n;i++)
    {
        seq.insert(a[i]);
        while ((*seq.rbegin())-(*seq.begin())>1)
        {
            seq.erase(seq.find(a[l]));
            l++;
        }
        if ((int)seq.size()>ans)
            ans=(int)seq.size();
    }
    printf("%d",ans);
    return 0;
}
