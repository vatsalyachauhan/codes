#include <iostream>
#include <cstdio>
#define fi(n) scanf("%d",&n)
using namespace std;


int main(){
	int t,n,result;
	fi(t);
	while(t--){
		fi(n);
		result = 0;
		if(n%2)
			printf("%d\n",n);
		else{
			while(n){
				result = (result<<1) + (n&1);
				n = n>>1;
			}
			printf("%d\n",result);
		}
	}return 0;
}