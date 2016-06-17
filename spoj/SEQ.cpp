#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef long long int lli;

#define 	pb(x) 		push_back(x)
#define 	sortA(v)	sort(v.begin(), v.end())
#define 	sortD(v)	sort(v.begin(), v.end(), greater<auto>())
#define 	mp(x,y) 	make_pair(x,y)
#define 	all(v) 		v.begin(),v.end() //Don’t put the whole right-hand side of these macros into parentheses – that would be wrong!
#define 	it(i,v) 	__typeof(v.begin()) i;
#define 	fill(a,val) 	memset(a,val,sizeof(a))
#define 	rep(i,a,b) 	for(__typeof(a) i = (a); i < (b) ; i++)
#define 	rev(i,a,b) 	for(__typeof(a) i = (a); i >= (b) ; i--)
#define 	tr(vec,it) 	for(__typeof(vec.begin()) it = vec.begin();it!=vec.end();++it)
#define 	present(container, element) (container.find(element) != container.end())
#define 	cpresent(container, element) (find(all(container),element) != container.end())

#define 	iss 		istringstream
#define 	oss 		ostringstream
#define 	sqr(x) 		(x)*(x)
#define 	ESP 		(1e-9)
#define 	PI 			3.1415926535897932384626433832795
#define 	MOD 		1000000000
#define     X 			first
#define     Y 			second
#define     pn          cout<<endl
#define 	vvl			vector<vector<lli> >
//g++ -std=c++11 your_file.cpp -o your_program

void product(vvl &a, vvl &b,int k){
	vvl c(k,vector<lli>(k,0));
	rep(i,0,k)rep(j,0,k)rep(l,0,k) c[i][j] = (c[i][j] + a[i][l]*b[l][j])%MOD;
	rep(i,0,k)rep(j,0,k) a[i][j] = c[i][j];
	return;
}

void power(vvl &base,int k, int n){
	if(n<=0) return;
	vvl ans(k,vector<lli>(k,0));
	rep(i,0,k) ans[i][i] = 1;
	while(n){
		if(n&1){
			product(ans,base,k);
		}
		product(base,base,k);
		n >>=1;
	}
	rep(i,0,k)base[0][i] = ans[0][i];
	return;
}

int main(){
	int t,k,n;
	cin>>t;
	while(t--){
		cin>>k;
		lli a[k];
		rep(i,0,k) cin>>a[i];
		vvl base(k,vector<lli>(k,0));
		rep(i,0,k) cin>>base[0][i];
		int i = 1;
		while(i<k){
			base[i][i-1]=1; i++;
		}
		cin>>n;

		power(base,k,n-k);
		if(n<=k)
			cout<<a[n-1]<<endl;
		else{
			lli ans = 0;
			rep(i,0,k) ans = (ans+base[0][i]*a[k-1-i])%MOD;
			cout<<ans<<endl;
		}
	}
	return 0;
}