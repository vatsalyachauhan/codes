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

using namespace std;

int main(){
	int t,s,temp,ans;
	fi(t);
	while(t--){
		fi(s);
		ans = 0;
		rep(i,1,s+1){
			fi(temp);
			if(temp&1) ans = ans^i;
		}
		cout<<(ans?"Tom Wins":"Hanks Wins")<<endl;
	}
	return 0;
}