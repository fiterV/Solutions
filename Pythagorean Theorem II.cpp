/*
  Name: Pythagorean Theorem II
  Copyright: Nothing
  Author: dyt
  Date: 10/01/15
  Description: Pythagorean Theorem II
*/
#include <iostream>
using namespace std;
bool sqr[100000001]={false};
int main()
{
    int n;
    cin>>n;
    for (int i=1;i*i<=100000000;i++)
        sqr[i*i]=true;
    int c=0;
    for (int i=1;i<=n;i++)
        for (int j=i;i*i+j*j<=n*n;j++)
            if (sqr[i*i+j*j]) c++;
    cout<<c;
    system("pause");
    return 0;
}
