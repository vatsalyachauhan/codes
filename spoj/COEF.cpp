#include <iostream>
#include <stdio.h>
using namespace std;
#define fi(n) scanf("%d",&n)
#define fii(n) scanf("%lld",&n)
#define lli long long int

lli fact(int k){
	lli result=1;
	while(k){
		result = result*k;
		k--;
	}
	return result;
}

int main(){
	int n,k,i,num;
	lli result;
	while(cin>>n>>k){
		result = fact(n);
		while(k--){
			fi(num);
			result = result/fact(num);
		}
		cout<<result<<endl;
	}return 0;
}