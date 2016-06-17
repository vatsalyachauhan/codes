#include <iostream>
#include <cstdio>
#include <math.h>
#include <vector>
#include <queue>
#define fi(n) scanf("%d",&n)
#define fii(n) scanf("%lld",&n)
#define lli long long int 
using namespace std;

lli func(lli h, lli k){
	return ((h*(h+1))/2 + 3*k*k -2*k*(h-1)-h);
}

lli min(lli a,lli b){
	return a>b?b:a;
}

int main(){
	int n;
	lli h,k,ans;
	fi(n);
	while(n--){
		ans = 0;
		fii(h);
		if(h){
			if((h-1)%3==0){
				k=(h-1)/3;
				ans = func(h,k);
			}
			else{
				k = (h-1)/3;
				ans = min(func(h,k),func(h,k+1));
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}