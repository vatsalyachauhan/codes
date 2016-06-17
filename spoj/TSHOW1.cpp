#include <iostream>
#include <cstdio>
#include <math.h>
#include <vector>
#include <queue>
#define fii(n) scanf("%lld",&n)
using namespace std;


int main(){
	long long int n,k,temp,num,extra;
	int digits,i;
	fii(n);
	while(n--){
		fii(k);
		temp = k;
		digits = 0; num =0;
		while(temp>num){
			num = num*2 + 2;
			digits++;
		}
		extra = temp - (num-2)/2 -1;
		int b[64] = {0};
		i=0;
		while(extra){
			b[i++] = extra%2;
			extra /= 2;
		}

		for(i=digits-1;i>=0;i--){
			printf("%d",5+b[i]);
		}
		printf("\n");
	}
	return 0;
}