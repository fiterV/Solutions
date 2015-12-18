#include <stdio.h>
#include <queue>
using namespace std;
int main()
{
    int n;
    long long x;
    freopen("huffman.in","r",stdin);
    freopen("huffman.out","w",stdout);
    scanf("%d",&n);
    priority_queue<long long,vector<long long>,greater<long long> > pq;
    for (int i=1;i<=n;i++)
    {
        scanf("%I64d",&x);
        pq.push(x);
    }
    long long ans=0;
    while (pq.size()!=1u)
    {
        long long a=pq.top();
        pq.pop();
        long long b=pq.top();
        pq.pop();
        ans+=a+b;
        pq.push(a+b);
    }
    printf("%I64d",ans);
    return 0;
}
