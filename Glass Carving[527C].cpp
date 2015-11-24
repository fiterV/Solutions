#include <iostream>
#include <set>
using namespace std;
int cntr[200001],cntc[200001];
int main()
{
	int w,h,n,c,nc,np,nn,tw,th;
	char t;
	set<int> sr,sc;
	set<int>::iterator it;
	cin>>w>>h>>n;
	sr.insert(0);
	sr.insert(w);
	sc.insert(0);
	sc.insert(h);
	cntr[w]=1;
	cntc[h]=1;
	tw=w;
	th=h;
	while (n--)
	{
		cin>>t>>c;
		if (t=='V')
		{
			sr.insert(c);
			it=sr.find(c);
		}
		else
		{
			sc.insert(c);
			it=sc.find(c);
		}
		it--;
		np=*it;
		it++;
		it++;
		nn=*it;
		if (t=='V')
		{
			cntr[nn-np]--;
			cntr[nn-c]++;
			cntr[c-np]++;
		}
		else
		{
			cntc[nn-np]--;
			cntc[nn-c]++;
			cntc[c-np]++;
		}
		while (!cntr[tw])
			tw--;
		while (!cntc[th])
			th--;
		cout<<(long long)tw*th<<endl;
	}
	return 0;
}
