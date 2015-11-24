#include <stdio.h>
char mp[9][9];
int determine()
{
    for (int i=1;i<=8;i++)
        if (mp[1][i]=='W')
            return 'A';
    for (int i=1;i<=8;i++)
        if (mp[8][i]=='B')
            return 'B';
    return 0;
}
int main()
{
    int i,j;
    for (i=1;i<=8;i++)
        scanf("%s",mp[i]+1);
    while (!determine())
    {
        for (i=2;i<=8;i++)
            for (j=1;j<=8;j++)
                if (mp[i][j]=='W'&&mp[i-1][j]!='B')
                {
                    mp[i-1][j]='W';
                    mp[i][j]='.';
                }
        if (determine())
            break;
        for (i=7;i>=1;i--)
            for (j=1;j<=8;j++)
                if (mp[i][j]=='B'&&mp[i+1][j]!='W')
                {
                    mp[i+1][j]='B';
                    mp[i][j]='.';
                }
    }
    printf("%c",determine());
    return 0;
}
