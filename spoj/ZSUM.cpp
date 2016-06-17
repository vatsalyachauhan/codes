#include <iostream>
#include <cstdio>
#include <math.h>
#include <vector>
#include <queue>
#define fi(n) scanf("%d",&n)
#define fii(n) scanf("%lld",&n)
#define lli long long int
#define M 10000007
using namespace std;

int mod(lli a){
	return a%M;
}

lli func(int a,int b){
	lli x = 1, y = a;
	while(b>0){
		if(b%2==1){
			x = (x*y)%M;
		}
		y = (y*y)%M;
		b >>= 1;
	}
	return x;
}


int main(){
	int n,k;
	fi(n);fi(k);
	while(1){
		printf("%d\n",mod(2*func(n-1,k) + func(n,k) + 2*func(n-1,n-1) + func(n,n)));
		fi(n);fi(k);
		if(n==0 && k==0)
			break;
	}
return 0;
}