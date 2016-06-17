#include <iostream>
#include <stdio.h>
#include <math.h>
#include <climits>
#include <functional>
#include <string>
#include <cstring>
#define fi(n) scanf("%d",&n)
#define fo(n) printf("%d\n",n)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define all(v) v.begin(),v.end()
#define it(i,v) __typeof(v.begin()) i;
#define set(a,val) memset(a,val,sizeof(a))
#define rep(i,a,b) for(__typeof(a) i = (a); i < (b) ; i++)
#define rev(i,a,b) for(__typeof(a) i = (a); i >= (b) ; i--)

using namespace std;

int main(){
	int n;
	fi(n);
	while(n){
		fo(4*n+1+(3*n*(n-1))/2);
		fi(n);
	}
	return 0;
}