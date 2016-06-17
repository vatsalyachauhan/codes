#include <iostream>
#include <cstdio>
#include <math.h>
#include <vector>
#include <queue>
#define fi(n) scanf("%d",&n)
using namespace std;

int main()
{
	int t,n,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&k);
		if((n-k)&((k-1)>>1))
			printf("0\n");
		else
			printf("1\n");
	}
	return 0;
}