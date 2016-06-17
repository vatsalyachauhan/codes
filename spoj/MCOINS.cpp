#include <iostream>
#include <cstdio>
#include <math.h>
#include <vector>
#include <queue>
#define fi(n) scanf("%d",&n)
using namespace std;

int main(){
	int k,l,m,i,max;
	fi(k);fi(l);fi(m);
	int a[m];
	max = 0;
	for(i=0;i<m;i++){
		fi(a[i]);
		if(a[i]>max) max = a[i];
	}
	bool b[max+1];
	b[0] = false; b[1] = true;
	for(i=2;i<=max;i++){
		b[i] = false;
		if(b[i-1]==false)
			b[i]=true;
		else if(i-k>=0 && b[i-k]==false)
			b[i]=true;
		else if(i-l>=0 && b[i-l]==false)
			b[i]=true;
	}
	for(i=0;i<m;i++){
		printf(b[a[i]]? "A" : "B");
	}
	printf("\n");
	return 0;
}