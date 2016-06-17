#include <iostream>
#include <cstdio>
#define fi(n) scanf("%lld",&n)

using namespace std;

int main(){
	int t;
	long long int r,a,b,c;

	scanf("%d",&t);
	while(t--){
		fi(a);fi(b);fi(c);
		r = a*a - 2*b;
		printf("%lld\n",r);
	}
	return 0;
}