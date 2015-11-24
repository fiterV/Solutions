#include <iostream>
using namespace std;
char mp[12][12][12];
bool vst[12][12][12];
int cnt;
/*
    Z     Y
     ^    ^
      \   |
       \  |
        \ |
         \----------->X
*/
//Buttom:x,y-1,z
//Left:x-1,y,z
//Right:x+1,y,z
//Front:x,y,z-1
//Behind:x,y,z+1
//Top:x,y+1,z
int dx[7]={0,0,-1,1,0,0,0};
int dy[7]={0,-1,0,0,0,0,1};
int dz[7]={0,0,0,0,-1,1,0};
void src(int x,int y,int z)
{
	int i;
	if (mp[x][y][z]=='#')
		return;
	vst[x][y][z]=true;
	cnt++;
	//Search All the Direct
	for (i=1;i<=6;i++)
		if (!vst[x+dx[i]][y+dy[i]][z+dz[i]])
			src(x+dx[i],y+dy[i],z+dz[i]);
}
int main()
{
	int n,m,k,x,y,z,px,py;
	cin>>k>>m>>n;
	for (x=0;x<12;x++)
		for (y=0;y<12;y++)
			for (z=0;z<12;z++)
				if (x==0||x==k+1||y==0||y==m+1||z==0||z==n+1)
				{
					mp[x][y][z]='#';
					vst[x][y][z]=true;
				}
	for (x=1;x<=k;x++)
		for (y=1;y<=m;y++)
			for (z=1;z<=n;z++)
				cin>>mp[x][y][z];
	cin>>px>>py;
	src(1,px,py);
	cout<<cnt;
	return 0;
}
