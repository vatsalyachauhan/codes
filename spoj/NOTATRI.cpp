#include <iostream>
#include <cstdio>
#include <math.h>
#include <vector>
#include <queue>
#include <algorithm>
#define fi(n) scanf("%d",&n)
using namespace std;

int counts[1000010] = {0};

int main(){
	int n,i,j,count;
	long long int answer;
	fi(n);
	while(n){
		int a[n];
		count=0;
		for(i=0;i<n;i++){
			fi(a[i]);
		}
		sort(a,a+n); 
		j = n-1;
		for(i=1000009;i>=0;i--){
			if(j>=0 && i==a[j]){
				while(j>=0 && i==a[j]){
					count++;j--;
				}
				counts[i] = count;
			}
			else{
				counts[i] = count;
			}
		}

		answer = 0;

		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				if((a[i]+a[j]+1)<1000010)
					answer = answer+ counts[a[i]+a[j]+1];
			}
		}
		printf("%lld\n",answer);
		for(i=0;i<1000010;i++)
			counts[i] = 0;
		fi(n);
	}
	return 0;
}