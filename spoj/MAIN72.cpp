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

int poss[101][100001];

int main(){
	int t,n;
	int arr[101];
	lli ans;
	int tempsum;
	fi(t);

	while(t--){
		set(arr,0); set(poss,0);
		ans = 0; tempsum = 0;
		fi(n);
		rep(i,1,n+1) {
			fi(arr[i]);
			tempsum += arr[i];
		}
		rep(i,0,n+1){
			poss[i][0] = 1;
		}
		rep(i,1,n+1){
			rep(j,1,tempsum+1){
				if(poss[i-1][j]==1 || ((j-arr[i]>=0) && (poss[i-1][j-arr[i]]==1))){
					poss[i][j] = 1;
				}
			}
		}
		rep(i,1,tempsum+1){
			ans += (poss[n][i]?i:0);
		}
		cout<<ans<<endl;
	}
	return 0;
}