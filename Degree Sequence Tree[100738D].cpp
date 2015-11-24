#include <stdio.h>
#include <deque>
#include <sstream>
using namespace std;
int d[200001];
deque<int> br,lf;
stringstream out;
int main()
{
	int n,i;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%d",d+i);
		if (i>1)
			d[i]--;
		if (!d[i])
			lf.push_back(i);
		else
			br.push_back(i);
	}
	while (br.size()>1)
	{
		int cur=br.front();
		br.pop_front();
		for (i=1;i<d[cur];i++)
		{
			if (lf.empty())
			{
				printf("-1");
				return 0;
			}
			out<<cur<<" "<<lf.front()<<endl;
			lf.pop_front();
		}
		out<<cur<<" "<<br.front()<<endl;
	}
	if (d[br.front()]!=lf.size())
		printf("-1");
	else
	{
		printf("%s",out.str().c_str());
		while (!lf.empty())
		{
			printf("%d %d\n",br.front(),lf.front());
			lf.pop_front();
		}
	}
	return 0;
}
