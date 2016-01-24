#include <stdio.h>
#include <string.h>
#define MOD 1000000009
#define M 30
struct matrix
{
    int mat[M][M];
    matrix()
    {
        memset(mat,0,sizeof(mat));
    }
    matrix(int num)
    {
        matrix();
        for (int i=0;i<M;i++)
            mat[i][i]=num;
    }
    matrix operator*(const matrix& b)
    {
        matrix ans;
        for (int i=0;i<M;i++)
            for (int j=0;j<M;j++)
                for (int k=0;k<M;k++)
                    ans.mat[i][j]=(ans.mat[i][j]+(long long)mat[i][k]*b.mat[k][j])%MOD;
        return ans;
    }
};
int k[50],f[50];
int main()
{
    matrix trans(0),ans(1),init(0);
    int n,c;
    long long m;
    scanf("%d%I64d%d",&n,&m,&c);
    for (int i=0;i<n;i++)
        scanf("%d",f+i);
    for (int i=0;i<n;i++)
        scanf("%d",k+i);
    for (int i=0;i<n-1;i++)
        trans.mat[i][i+1]=1;
    for (int i=0;i<n;i++)
        trans.mat[n-1][n-k[i]]++;
    for (m--;m;m/=2)
    {
        if (m%2)
            ans=ans*trans;
        trans=trans*trans;
    }
    long long res=0;
    for (int i=0;i<n;i++)
        res=(res+(long long)ans.mat[0][i]*f[i])%MOD;
    printf("%I64d",res);
    return 0;
}
