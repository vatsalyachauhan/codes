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
	int t,n,loops,temp;
	fi(t);
	while(t--){
		fi(n);
		int a[n];
		lli sum = 0; temp =1;
		rep(i,0,n) fi(a[i]);
		loops = n/2;
		rep(i,0,loops){
			sum += (n-temp)*(a[n-1-i] - a[i]);
			temp = temp +2;
		} 
		cout << sum <<endl;
	}
	return 0;
}