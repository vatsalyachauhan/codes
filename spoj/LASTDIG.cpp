#include <iostream>
#include <stdio.h>
#define fi(n) scanf("%d",&n)
#define fo(n) printf("%d\n",n)

using namespace std;

int last_digit(int a,int b){
	if(b==0) return 1;
	if(b==1) return a; 
	int ans = last_digit(a,b/2);
	return (ans*ans*(b%2 ? a : 1)) % 10;
}

int main(){
	int t,a,b;
	fi(t);
	while(t--){
		fi(a);fi(b);
		if(a%10==0) fo(0);
		else if(a%10 == 1) fo(1);
		else fo(last_digit(a,b));
	}
	return 0;
}