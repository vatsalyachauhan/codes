#include <iostream>
#include <stdio.h>
#include <cmath>
#define fo(n) printf("%d",n)
#define fi(n) scanf("%d",&n)
#define EXP 2.7182818284590452353602874713527
#define PI 3.141592653589793238462643383279502
using namespace std;


int main(){
	long long int n,ans;
	int t;
	fi(t);
	while(t--){
		scanf("%lld",&n);
		if(n<2)
			cout<<1<<endl;
		else{
			ans = (0.5*log(2*PI*n) + n*(log(n) - 1))/log(10) +1 ;
			printf("%lld\n",ans);
		}
	}
	return 0;
}