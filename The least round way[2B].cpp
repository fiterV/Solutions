#include <stdio.h>
#include <algorithm>
using namespace std;
char prev[1001][1001][2],path[2002];
int dp[1001][1001][2];
int factors(int num,int base)
{
    int ret=0,fct=base;
    if (!num)
        return 1;
    while (num%fct==0)
    {
        ret++;
        fct*=base;
    }
    return ret;
}
int main()
{
    int n,zero_i,i,j,k,x;
    scanf("%d",&n);
    bool zero=false;
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
        {
            scanf("%d",&x);
            if (!x)
            {
                zero=true;
                zero_i=i;
            }
            dp[i][j][0]=factors(x,2);
            dp[i][j][1]=factors(x,5);
        }
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
            for (k=0;k<2;k++)
                if (i||j)
                {
                    if (!i)
                    {
                        dp[i][j][k]+=dp[i][j-1][k];
                        prev[i][j][k]='R';
                    }
                    else if (!j)
                    {
                        dp[i][j][k]+=dp[i-1][j][k];
                        prev[i][j][k]='D';
                    }
                    else
                    {
                        dp[i][j][k]+=dp[i-1][j][k]<dp[i][j-1][k]?dp[i-1][j][k]:dp[i][j-1][k];
                        prev[i][j][k]=dp[i-1][j][k]<dp[i][j-1][k]?'D':'R';
                    }
                }
    if (min(dp[n-1][n-1][0],dp[n-1][n-1][1])>1&&zero)
    {
        printf("1\n");
        for (i=0;i<zero_i;i++)
            printf("D");
        for (i=0;i<n-1;i++)
            printf("R");
        for (i=zero_i;i<n-1;i++)
            printf("D");
    }
    else
    {
        int path_len=0,k=dp[n-1][n-1][0]>dp[n-1][n-1][1];
        printf("%d\n",min(dp[n-1][n-1][0],dp[n-1][n-1][1]));
        for (i=n-1,j=n-1;i||j;)
        {
            path[path_len++]=prev[i][j][k];
            if (prev[i][j][k]=='D')
                i--;
            else if (prev[i][j][k]=='R')
                j--;
        }
        reverse(path,path+2*(n-1));
        printf("%s",path);
    }
    printf("\n");
    return 0;
}
