/*
1������
2���ж�BERLAND������һ���������
3���������ж�����֡���ʤ������ʤ����
4������
5������BERLAND���һ�����ֲ��
6��
��1������3�� 
���IMPOSSIBLE
��2��С�ڵ���3�� 
<1>��һ����һ֧����
�жϾ�ʤ������࣬��������Ϊ������
<2>��һ������֧����
<1>��ʤ�����ֱ�Ϊx1,x2��BERLANDΪx3
<2>������Ϊmin(x1,x2)-x3
*/
#include <iostream>
#include <string>
#include <stdlib>
#include <map>
#include <set>
#include <stdio.h>
#include <cstdio>
using namespace std;
struct match
{
	string tm1;
	string tm2;
	int scr1;
	int scr2;
};
int main()
{
	int i,m1,m2;
	string s,tm[5];
	match m[7];
	map<string,int> mcnt;
	for (i=1;i<=5;i++)
		scanf("%s%s%d:%d",&m[i].tm1,&m[i].tm2,&m[i].scr1,&m[i].scr2);
	m[6].tm1="BERLAND";
	for (i=1;i<=5;i++)
	{
		mcnt[m[i].tm1]++;
		mcnt[m[i].tm2]++;
	}
	for (i=0;i<5;i++)
		if (mcnt.at(i)==2)
			//
}
