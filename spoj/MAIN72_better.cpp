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
	int t,n;
	int arr[100];
	int poss [100001];
	int final[100001];

	lli ans;
	int tempsum;
	fi(t);

	while(t--){
		set(arr,0); set(poss,0); set(final,0);
		ans = 0; tempsum = 0;
		fi(n);
		rep(i,0,n) {
			fi(arr[i]);
			tempsum += arr[i];
		}
		sort(arr,arr+n);
		

		rep(i,0,n){
			poss[0] = 1;
			rep(j,1,tempsum+1){
				if(poss[j]==1) continue;
				else if((j-arr[i]>=0) && (poss[j-arr[i]]==1)){
					poss[j] = 1;
					final[j] = 1;
				}
			}
			rep(k,0,tempsum+1){
				cout<<poss[k]<<" ";
			}
			cout<<"\n";
		}
		rep(i,1,tempsum+1){
			ans += (final[i]?i:0);
		}
		cout<<ans<<endl;
	}
	return 0;
}