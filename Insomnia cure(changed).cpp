/*
  Name: Insomnia cure(changed)
  Copyright: Nothing
  Author: dyt
  Date: 16/01/15
  Description: Insomnia cure(changed)
*/
/*
The expression of four collections:
    |A1?A2?A3?A4|=|A1|+|A2|+|A3|+|A4|
    -|A1��A2|-|A1��A3|-|A1��A4|-|A2��A3|-|A2��A4|-|A3��A4|
    +|A1��A2��A3|+|A1��A2��A4|+|A1��A3��A4|+|A2��A3��A4|
    -|A1��A2��A3��A4|
*/
#include <iostream>
using namespace std;
int k,l,m,n,d,z;
int main()
{
    cin>>k>>l>>m>>n>>d;
    //|A1|+|A2|+|A3|+|A4|
    z=d/k+d/l+d/m+d/n;
    //-|A1��A2|-|A1��A3|-|A1��A4|-|A2��A3|-|A2��A4|-|A3��A4|
    z=z-d/k/l-d/k/m-d/k/n-d/l/m-d/l/n-d/m/n;
    //+|A1��A2��A3|+|A1��A2��A4|+|A1��A3��A4|+|A2��A3��A4|
    z=z+d/k/l/m+d/k/l/n+d/k/m/n+d/l/m/n;
    //-|A1��A2��A3��A4|
    z=z-d/k/l/m/n;
    cout<<z;
    system("pause");
    return 0;
}
