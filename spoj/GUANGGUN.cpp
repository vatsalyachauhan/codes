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

int main(){
	lli n;
	while(scanf("%lld",&n)!=EOF){
		cout<<(81*(n/9) + (n%9)*(n%9))<<endl;
	}
	return 0;
}