#include <iostream>
#include <string>
#include <map>
using namespace std;
string grid=".........";
map<string,string> mp;
bool win(char c)
{
	int i;
	if (grid[0]==c&&grid[4]==c&&grid[8]==c||grid[2]==c&&grid[4]==c&&grid[6]==c) return true;
	for (i=0;i<3;i++)
		if (grid[i*3]==c&&grid[i*3+1]==c&&grid[i*3+2]==c||grid[i]==c&&grid[3+i]==c&&grid[6+i]==c) return true;
	return false;
}
void dfs(int k)
{
	if (win('X'))
	{
		mp[grid]="the first player won";
		return;
	}
	else if (win('O'))
	{
		mp[grid]="the second player won";
		return;
	}
	else if (k==8)
	{
		mp[grid]="draw";
		return;
	}
	else if (k%2==1)
		mp[grid]="second";
	else
		mp[grid]="first";
	int i;
	for (i=0;i<9;i++)
		if (grid[i]=='.')
		{
			if (k%2==1)
			
		}
}
