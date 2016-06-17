#include <iostream>
#include <cstdio>
#include <math.h>
#include <vector>
#include <queue>
#include <limits.h>
#define fi(n) scanf("%d",&n)
using namespace std;

void generate(int *op, int i, int size){
	int j;
	for(j=0;j<size;j++){
		op[j] = ((i)&(1<<(size-j-1))) ? -1 : 1;
	}
	return;
}

int main(){
	int n,d,i,j,p,q,r,num,max,min;
	fi(n);fi(d);
	int a[n][d];
	for(i=0;i<n;i++){
		for(j=0;j<d;j++){
			fi(a[i][j]);
		}
	}

	int maximumAnswer =0;
	for(i=0;i<(1<<(d-1));i++){
		int operators[d-1];
		generate(operators,i,d-1);
		max = INT_MIN; min = INT_MAX;
		for(p=0;p<n;p++){
			num = a[p][0];
			for(q=0;q<d-1;q++){
				num = num + operators[q]*a[p][q+1];
			}
			if(num > max)
				max = num;
			if(num < min)
				min = num;
		}

		if(maximumAnswer < max-min)
			maximumAnswer = max-min;
	}
	printf("%d\n",maximumAnswer);
	return 0;
}