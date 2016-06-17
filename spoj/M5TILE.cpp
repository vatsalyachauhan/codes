#include <iostream>
#include <cstdio>
#include <math.h>
#include <vector>
#include <queue>
#define fi(n) scanf("%d",&n)
using namespace std;

int main(){
	int i;
	long long int T[36], F[36];
	T[0]=1; F[0]=0;

	for(i=1; i<35; i++){
		if(i%2){
			T[i]=0;
			F[i] = T[i-1] + ((i>=2)?5*F[i-2]:0);
		}
		else{
			T[i] = ((i>=2)?8*T[i-2]:0) + ((i>=3)?16*F[i-3]:0);
			F[i]=0;
		}
		
	}

	for(i=1;i<18;i++){
		printf("%lld\n",T[2*i]);
	}

	return 0;
}