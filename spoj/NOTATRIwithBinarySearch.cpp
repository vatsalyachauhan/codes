#include <iostream>
#include <cstdio>
#include <math.h>
#include <vector>
#include <queue>
#include <algorithm>
#define fi(n) scanf("%d",&n)
using namespace std;

int binarysearch(int *a, int lo, int hi, int key){
	if(lo==hi)
		return lo;
	int mid = (lo+hi)/2;
	if(a[mid]<=key)
		return binarysearch(a,mid+1,hi,key);
	else if(a[mid]>key && a[mid-1]<= key)
		return mid;
	else
		return binarysearch(a,lo,mid,key);
}


int main(){
	int n,i,j,count;
	int answer;
	fi(n);
	while(n){
		int a[n];
		for(i=0;i<n;i++){
			fi(a[i]);
		}
		sort(a,a+n); 

		answer = 0;

		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				if(a[i]+a[j]<a[n-1])
					answer = answer + n - binarysearch(a,0,n-1,a[i]+a[j]);
			}
		}
		printf("%d\n",answer);
		fi(n);
	}
	return 0;
}