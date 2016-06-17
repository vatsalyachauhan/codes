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
	int t,n,temp,ans,cnt;
	fi(t);
	while(t--){
		fi(n);
		ans = 0;
		cnt = 0;
		rep(i,0,n){
			fi(temp);
			if(temp==1) cnt++;
			ans = ans^temp;
		}
		if(cnt==n){
			cout<<((n&1)?"Brother":"John")<<endl;
		}else
			cout<<(ans?"John":"Brother")<<endl;
	}
	return 0;
}