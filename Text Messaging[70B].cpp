#include <stdio.h>
#include <string>
using namespace std;
int main()
{
    char cur;
    string buf,pt;
    int n,ans=0,lastpos=-1;
    scanf("%d%*c",&n);
    while (scanf("%c",&cur)!=-1)
    {
        if (cur==13||cur==10)
            continue;
        buf+=cur;
        pt+=cur;
        if (cur=='.'||cur=='?'||cur=='!')
        {
            if ((int)buf.size()>n)
            {
                while (pt[0]==' ')
                    pt=pt.substr(1);
                if ((int)pt.size()>n)
                {
                    printf("Impossible");
                    return 0;
                }
                ans++;
                buf=buf.substr(lastpos+1);
                while (buf[0]==' ')
                    buf=buf.substr(1);
            }
            lastpos=(int)buf.size()-1;
            pt="";
        }
    }
    printf("%d",ans+(buf!=""?1:0));
    return 0;
}
