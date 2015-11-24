#include <iostream>
using namespace std;
char nm[200001],ab[256];
int main()
{
    int n,m,i;
    char a,b;
    cin>>n>>m;
    for (i=1;i<=n;i++)
        cin>>nm[i];
    for (i=0;i<256;i++)
        ab[i]=i;
    while (m--)
    {
        cin>>a>>b;
        for (i='a';i<='z';i++)
            if (ab[i]==a)
                ab[i]=b;
            else if (ab[i]==b)
                ab[i]=a;
    }
    for (i=1;i<=n;i++)
        cout<<ab[nm[i]];
    return 0;
}
