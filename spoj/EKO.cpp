#include <iostream>
#include <stdio.h>
#include <math.h>
#include <climits>
#define fi(n) scanf("%d",&n)
#define fo(n) printf("%d",n)
using namespace std;

bool isfeasible(int arr[],int n,int m,int h){
	int sum = 0,i;
	for(i=0;i<n;i++){
		sum +=  (arr[i]>h ? arr[i]-h : 0);
		if(sum>=m)
			return true; 
	}
	return false;
}

int bin_search(int arr[],int n,int l,int r,int m){
	int mid;
	if(l==r)
		return l;
	if(l+1==r){
		if(isfeasible(arr,n,m,r))
			return r;
		else
			return l;
	}
	mid = (l+r)/2;
	if(isfeasible(arr,n,m,mid))
		return bin_search(arr,n,mid,r,m);
	else
		return bin_search(arr,n,l,mid-1,m);
}


int main(){
	int n,m,mid,l,r,i,max=-1;

	fi(n);fi(m);
	int arr[n];
	for(i=0;i<n;i++){
		fi(arr[i]);
		if(arr[i]>max)
			max = arr[i];
	}
	cout<<bin_search(arr,n,0,max,m)<<endl;
	return 0;
}