#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define max(a,b) ((a)>(b)?(a):(b))
int n,h,s[51],p[51],m[51],mod;
char ans[51];
int _hash(int mon,int heal,int str,int sp,int mp)
{
    int ret=mon;
    ret=ret*mod+heal;
    ret=ret*mod+str;
    ret=ret*mod+sp;
    ret=ret*mod+mp;
    return (ret%1000007+1000007)%1000007;
}
bool failed[1000007];
bool dfs(int mon,int heal,int str,int sp,int mp)
{
    if (mon>n)
    {
        printf("%s\n",ans+1);
        return true;
    }
    if (failed[_hash(mon,heal,str,sp,mp)])
        return false;
    if (str>=s[mon]&&heal-max(2*s[mon]-str,0)>0)
    {
        ans[mon]='D';
        if (dfs(mon+1,heal-max(2*s[mon]-str,0),str+1,sp,mp))
            return true;
    }
    if (sp>=p[mon]&&mp>=m[mon])
    {
        ans[mon]='E';
        if (dfs(mon+1,heal,str,sp+1,mp-m[mon]))
            return true;
    }
    failed[_hash(mon,heal,str,sp,mp)]=true;
    return false;
}
int main()
{
    int i,is,isp,im;
    freopen("princess.in","r",stdin);
    freopen("princess.out","w",stdout);
    srand(time(0));
    mod=(int)(((float)rand()/RAND_MAX)*100)+161;
    while (scanf("%d%d%d%d%d",&n,&h,&is,&isp,&im)!=EOF)
    {
        for (i=1;i<=n;i++)
            scanf("%d%d%d",s+i,p+i,m+i);
        memset(failed,false,sizeof(failed));
        if (!dfs(1,h,is,isp,im))
            printf("UNLUCKY\n");
    }
    return 0;
}
