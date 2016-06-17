#include <bits/stdc++.h>
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

lli abc[1000000];
lli def[1000000];

int main(){
	int n,p=0,q=0;
	fi(n);
	int arr[n];
	lli ans=0;
	lli *p1,*p2;
	rep(i,0,n) fi(arr[i]);
	rep(i,0,n)rep(j,0,n)rep(k,0,n) {
		abc[p++] = arr[i]*arr[j]+arr[k];
		if(arr[k])
			def[q++] = (arr[i]+arr[j])*arr[k];
	}
	sort(def,def+q);
	rep(i,0,p){
		p1 = lower_bound(def,def+q,abc[i]);
		p2 = upper_bound(def,def+q,abc[i]);
		ans += p2-p1;
	}
	cout<<ans<<endl;
	return 0;
}