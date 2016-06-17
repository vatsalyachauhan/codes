#include <iostream>
#include <stdio.h>
#include <math.h>
#include <climits>
#include <functional>
#include <string>
#include <cstring>
#include <algorithm>
#define fi(n) scanf("%d",&n)
#define fo(n) printf("%d",n)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define all(v) v.begin(),v.end()
#define it(i,v) __typeof(v.begin()) i;
#define set(a,val) memset(a,val,sizeof(a))
#define rep(i,a,b) for(__typeof(a) i = (a); i < (b) ; i++)
#define rev(i,a,b) for(__typeof(a) i = (a); i >= (b) ; i--)
#define lli long long int
using namespace std;

int sumuptoI[]={0,1,3,6,10,15,21,28,36,45};
int powof10[]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
int digits[10];
int numdig(lli a){
	int i=0;
	while(a){
		digits[i] = a%10;
		a /=10;
		i++;
	}
	return i;
}
 
lli fun(lli b){
	lli a=b;
	int ld,deg;
	lli result=0;
	if(b<1) return 0;
	int numdigits = numdig(a);
	result = (numdigits-1)*45*(powof10[numdigits-1]/10);
	rev(i,numdigits-1,0){
		if(digits[i]){
			result += sumuptoI[digits[i]-1]*powof10[i] + (digits[i]-1)*45*i*(powof10[i]/10);
			b = b - digits[i]*powof10[i];
			result += digits[i]*(b+1); 
		}
	}
	return result;
}
 
int main(){
	int a,b;
	fi(a);fi(b);
	while(!(a==-1&&b==-1)){
		printf("%lld\n",fun(b)-fun(a-1));
		fi(a);fi(b);
	}
	return 0;
} 