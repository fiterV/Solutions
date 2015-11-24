//Beautiful Year
//2015/1/10
//dyt
//Beautiful Year
#include <iostream>
using namespace std;
int main()
{
    int year;
    cin>>year;
    int i,d1,d2,d3,d4;
    for (i=year+1;;i++)
    {
        d1=i/1000;
        d2=i/100%10;
        d3=i/10%10;
        d4=i%10;
        if (d1!=d2&&d1!=d3&&d1!=d4&&d2!=d3&&d2!=d4&&d3!=d4)
        {
            break;
        }
    }
    cout<<i;
    system("pause");
    return 0;
}
