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

int table[6110][6110];

int main(){
	std::ios::sync_with_stdio(false);
	int t,n,j,i,gap,l,h;
	fi(t);
	string str;
	while(t--){
		cin>>str; n = str.length();
		rep(i,0,n)rep(j,0,n) table[i][j]=0;
		for (gap = 1; gap < n; ++gap)
	        for (l = 0, h = gap; h < n; ++l, ++h)
	            table[l][h] = ((str[l] == str[h])? (table[l+1][h-1]) : (min(table[l][h-1], table[l+1][h]) + 1));
		cout<<table[0][n-1]<<endl;
	}
	return 0;
}