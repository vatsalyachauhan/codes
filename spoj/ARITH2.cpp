#include <bits/stdc++.h>
#define fi(n) scanf("%lld",&n)
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
	lli num,ans;
	int t;
	cin>>t;
	char c[20];
	string str;
	while(t--){
		fi(ans);
		scanf("%s",c);
		while(c[0]!='='){
			if(c[0]=='+'){
				fi(num); ans += num;
			}
			else if(c[0]=='-'){
				fi(num); ans -= num;
			}
			else if(c[0]=='*'){
				fi(num);ans *= num;
			}
			else if(c[0]=='/'){
				fi(num);ans /= num;
			}
			else if(c[0]=='%'){
				fi(num); ans %= num;
			}
			scanf("%s",c);
		}
		cout<<ans<<endl;
	}
	return 0;
}