#include <iostream>
#include <cstdio>
#include <math.h>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <algorithm>
#define fi(n) scanf("%d",&n)
using namespace std;

int main(){
	int n,k,i,j;
	long long int count=0;
	fi(n);fi(k);
	int a[n];
	for(i=0;i<n;i++){
		fi(a[i]);
	}
	sort(a,a+n);
	i=0;j=0;
	while(j<n){
		if(a[j]-a[i]==k){
			count++;
			i++;j++;
		}
		else if(a[j]-a[i]<k)
			j++;
		else
			i++;
	}
	printf("%lld\n",count);
	return 0;
}