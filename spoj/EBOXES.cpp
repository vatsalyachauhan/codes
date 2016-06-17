#include <iostream>
#include <cstdio>
#include <math.h>
#define fi(n) scanf("%d",&n)
using namespace std;


int main(){
	int i,n,k,t,f,temp;
	fi(i);
	while(i--){
		fi(n);fi(k);fi(t);fi(f);
		f = f-n;
		temp = f/(k-1);
		printf("%d\n",n+temp*k);
	}
	return 0;
}