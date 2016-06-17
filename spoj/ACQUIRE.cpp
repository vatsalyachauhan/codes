#include <bits/stdc++.h>
#define fi(n) scanf("%d",&n)
#define fii(n) scanf("%lld",&n)
#define fo(n) printf("%d",n)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define all(v) v.begin(),v.end()
#define it(i,v) __typeof(v.begin()) i;
#define set(a,val) memset(a,val,sizeof(a))
#define rep(i,a,b) for(__typeof(a) i = (a); i < (b) ; i++)
#define rev(i,a,b) for(__typeof(a) i = (a); i >= (b) ; i--)
#define lli long long int 
#define vi vector<int> 
#define pii pair<int,int> 
#define iss istringstream 
#define oss ostringstream 
#define sqr(x) (x)*(x)
#define ESP (1e-9)
#define PI 3.1415926535897932384626433832795
#define ps printf(" ")
#define pn printf("\n")
#define dg(n,s); printf("%s %d",s,n)
#define imax numeric_limits<int>::max()
#define imin numeric_limits<int>::min()
#define lmax numeric_limits<ll>::max()
#define lmin numeric_limits<ll>::min()
using namespace std;

//compile command== g++ -std=c++11

int main(){
	std::ios::sync_with_stdio(false);
	int n;
	int l,r,maxl,maxw;
	fi(n);
	lli ans = 0,price_including,price_excluding,collected;
	vector<pii > v;
	rep(i,0,n){
		fi(l);fi(r);
		v.pb(pii(l,r));
	}
	sort(v.rbegin(),v.rend());
	vector<pii >::iterator  itr = v.begin();
	maxl = itr->first;
	maxw = itr->second;
	itr++;
	while(itr!=v.end()){
		collected = maxl*maxw;
		price_excluding = collected + (itr->first*itr->second);
		if(maxl < itr->first) maxl = itr->first;
		if(maxw < itr->second) maxw = itr->second;
		price_including = maxl*maxw;
		if(price_including>price_excluding){
			maxl = itr->first;
			maxw = itr->second;
			ans += collected; 
		}
		itr++;
	}
	ans += maxl*maxw;
	cout<<ans<<endl;
	return 0;
}