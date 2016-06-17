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

int main(){
	int c,n,k,b,t,lazy,ans,passed;
	fi(c); c++;
	rep(i,1,c){
		lazy = 0;
		ans = 0;
		passed = 0;
		fi(n);fi(k);fi(b);fi(t);
		int x[n];
		int v[n];
		rep(j,0,n) fi(x[j]);
		rep(j,0,n) fi(v[j]);
		rep(j,0,n) x[j] += v[j]*t;
		rev(j,n-1,0){
			if(passed >= k) 
				break;
			else if(x[j]>=b){
				ans += lazy;
				passed++;
			}
			else if(x[j]<b){
				lazy++;
			}
		}
		printf("Case #%d: ",i);
		if(passed>=k){
			printf("%d\n",ans);
		}
		else{
			printf("IMPOSSIBLE\n");
		}
	}
	return 0;
}