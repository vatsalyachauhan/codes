#include <iostream>
#include <cstdio>
#include <math.h>
#include <vector>
#include <queue>
#define fi(n) scanf("%d",&n)
#define fii(n) scanf("%lld",&n)
#define lli long long int 
using namespace std;

lli func(int *a, int n, int x){
	int i;
	lli sum = 0;
	for(i=0;i<n;i++){
		sum = sum*x + a[i];
	}
	return sum;
}


int main(){
	int n,k,t=1,x,i;
	lli val;
	fi(n);
	while(n!=-1){
		int a[n+1];
		for(i=0;i<n+1;i++){
			fi(a[i]);
		}
		fi(k);
		printf("Case %d:\n",t);
		while(k--){
			fi(x);
			printf("%lld\n",func(a,n+1,x));
		}
		fi(n);t++;
	}
	return 0;
}