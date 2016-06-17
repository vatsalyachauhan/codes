#include <iostream>
#include <cstdio>
#include <math.h>
#include <vector>
#include <queue>
#define fi(n) scanf("%d",&n)
using namespace std;

long long int comb[74][74]={0};


int main(){
	int p, i,j, n;

	comb[0][0]=1;
	for(i=1;i<75;i++){
		for(j=1;j<i;j++){
			comb[i][j]=comb[i-1][j-1]+comb[i-1][j];
		}
		comb[i][0] = comb[i][i] = 1;
	}

	fi(p);
	while(p--){
		fi(i);fi(n);
		printf("%d %lld\n",i,comb[9+n][9]);
	}
	return 0;
}