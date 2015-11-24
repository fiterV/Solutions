#include <stdio.h>
void print(int n)
{
	if (n)
	{
		printf("((A%d|B%d)|(",n,n);
		print(n-1);
		printf("|((A%d|A%d)|(B%d|B%d))))",n,n,n,n);
	}
	else
		printf("((A%d|B%d)|(A%d|B%d))",n,n,n,n);
}
int main()
{
	int n;
	scanf("%d",&n);
	print(n-1);
	return 0;
}
