#include <iostream>
#include <cstdio>
#include <math.h>
#include <vector>
#include <queue>
#include <algorithm>
#define fi(n) scanf("%d",&n)
using namespace std;

int main(){
	int n,i;
	bool flag;
	fi(n);
	while(n){
		int a[n];
		for(i=0;i<n;i++) fi(a[i]);
		sort(a,a+n); flag = true;
		for(i=1;i<n;i++){
			if(a[i]-a[i-1]>200){
				flag = false; break;
			}
		}
		if(flag){
			flag = (2*(1442-a[n-1]) > 200)?false:true;
		}
		printf(flag?"POSSIBLE\n":"IMPOSSIBLE\n");
		fi(n);
	}
}