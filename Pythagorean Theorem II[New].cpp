#include <iostream>
using namespace std;
int main()
{
    int n,m,k,cnt=0;
    cin>>n;
    for (m=3;m<=n;m++)
        if (m%2==1)
        {
           for (k=1;k<m;k++)
               if (m*m%k==0&&(m*m/k+k)/2<=n)
			   		cnt++;
        }
        else
        {
            for (k=2;k<m;k+=2)
               if ((m*m/2)%k==0&&(m*m/k+k)/2<=n)
			   		cnt++;
        }
    cout<<cnt/2;
    return 0;
}
