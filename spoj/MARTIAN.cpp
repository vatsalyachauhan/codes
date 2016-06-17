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
#define dg(n,s); printf("%s %d",s,n)
#define imax numeric_limits<int>::max()
#define imin numeric_limits<int>::min()
#define lmax numeric_limits<ll>::max()
#define lmin numeric_limits<ll>::min()
using namespace std;

//compile command== g++ -std=c++11 mycode.cpp

int main(){
	int rows,cols;
	fi(rows);fi(cols);
	while(rows + cols){
		int yey[rows][cols];
		int blo[rows][cols];
		int yey_cum[rows][cols];
		int blo_cum[rows][cols];
		rep(i,0,rows)rep(j,0,cols) fi(yey[i][j]);
		rep(i,0,rows)rep(j,0,cols) fi(blo[i][j]);
		rep(i,0,rows) yey_cum[i][0] = yey[i][0];
		rep(j,0,cols) blo_cum[0][j] = blo[0][j];
		rep(i,0,rows)rep(j,1,cols){
			yey_cum[i][j] = yey[i][j] + yey_cum[i][j-1];
		}
		rep(i,1,rows)rep(j,0,cols){
			blo_cum[i][j] = blo[i][j] + blo_cum[i-1][j]; 
		}
		rows++; cols++;
		int dp[rows][cols];
		rep(i,0,rows) dp[i][0] = 0;
		rep(j,0,cols) dp[0][j] = 0;
		rep(i,1,rows)rep(j,1,cols){
			dp[i][j] = max(dp[i][j-1] + blo_cum[i-1][j-1], dp[i-1][j]+ yey_cum[i-1][j-1]);
		}
		fo(dp[rows-1][cols-1]);pn;
		fi(rows);fi(cols);
	}
	return 0;
}
