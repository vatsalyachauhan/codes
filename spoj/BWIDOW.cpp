#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#define M 1000000007
#define lli long long lli
using namespace std;
#define fi(n) scanf("%d",&n)
#include <limits.h>

int main(){
	int t,maxi,maxo,i,l,r,max2,index,n;
	fi(t);
	while(t--){
		fi(n);
		maxo = INT_MIN;
		maxi = INT_MAX;
		max2 = INT_MIN;
		for(i=1;i<=n;i++){
			fi(l);fi(r);
			if(r>=maxo){
				max2 = maxo;
				maxo = r;
				maxi = l;
				index = i;
			}
			if(r>max2 && r<maxo){
				max2 = r;
			}
		}
		if(maxi > max2){
			printf("%d\n",index);
		}
		else{
			printf("-1\n");
		}
	}return 0;
}