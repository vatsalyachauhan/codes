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
#define tr(vec,it) for(__typeof(vec.begin()) it = vec.begin();it!=vec.end();++it)
#define lli long long int
#define vi vector<int>
#define pii pair< int ,int >
#define iss istringstream
#define oss ostringstream
#define sqr(x) (x)*(x)
#define ESP (1e-9)
#define PI 3.1415926535897932384626433832795
#define ps printf(" ")
#define pn printf("\n")
using namespace std;

//compile command== g++ -std=c++11 mycode.cpp

int main(){
	int m,n,k,ans=0;
	cin>>m>>n>>k;
	string a[m];
	rep(i,0,m) cin>>a[i];
	m++; n++;
	int dp[m][n];
	rep(p,1,m)rep(q,1,n){
		memset(dp,0,sizeof(dp));
		rep(r,p,m)rep(s,q,n){
			dp[r][s] = dp[r-1][s] | dp[r][s-1] | (1<<(a[r-1][s-1]-'A'));
		}
		rep(r,p,m)rep(s,q,n){
			int temp = __builtin_popcount(dp[r][s]);
			if(temp==k) ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
