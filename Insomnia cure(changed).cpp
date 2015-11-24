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
    -|A1¡ÈA2|-|A1¡ÈA3|-|A1¡ÈA4|-|A2¡ÈA3|-|A2¡ÈA4|-|A3¡ÈA4|
    +|A1¡ÈA2¡ÈA3|+|A1¡ÈA2¡ÈA4|+|A1¡ÈA3¡ÈA4|+|A2¡ÈA3¡ÈA4|
    -|A1¡ÈA2¡ÈA3¡ÈA4|
*/
#include <iostream>
using namespace std;
int k,l,m,n,d,z;
int main()
{
    cin>>k>>l>>m>>n>>d;
    //|A1|+|A2|+|A3|+|A4|
    z=d/k+d/l+d/m+d/n;
    //-|A1¡ÈA2|-|A1¡ÈA3|-|A1¡ÈA4|-|A2¡ÈA3|-|A2¡ÈA4|-|A3¡ÈA4|
    z=z-d/k/l-d/k/m-d/k/n-d/l/m-d/l/n-d/m/n;
    //+|A1¡ÈA2¡ÈA3|+|A1¡ÈA2¡ÈA4|+|A1¡ÈA3¡ÈA4|+|A2¡ÈA3¡ÈA4|
    z=z+d/k/l/m+d/k/l/n+d/k/m/n+d/l/m/n;
    //-|A1¡ÈA2¡ÈA3¡ÈA4|
    z=z-d/k/l/m/n;
    cout<<z;
    system("pause");
    return 0;
}
