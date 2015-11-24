/*
1、输入
2、判断BERLAND将与哪一个队伍比赛
3、计算所有队伍积分、净胜球数、胜球数
4、排序
5、计算BERLAND与第一名积分差距
6、
（1）超过3分 
输出IMPOSSIBLE
（2）小于等于3分 
<1>第一名有一支队伍
判断净胜球数差距，并将其作为进球数
<2>第一名有两支队伍
<1>净胜球数分别为x1,x2。BERLAND为x3
<2>进球数为min(x1,x2)-x3
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
