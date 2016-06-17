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
	int n,j,i;
	while(fi(n)>0){
		int a[n][n];
		rep(k,0,n) fi(a[k][k]);
		int smoke[n][n];
		memset(smoke,0,sizeof(smoke));
		rep(k,1,n){
			i=0; j = k;
			while(j<n){
				a[i][j] = (a[i][i] + a[i+1][j])%100;
				smoke[i][j] = a[i][i]*a[i+1][j] + smoke[i][i] + smoke[i+1][j];
				rep(var,i+1,j){
					if(smoke[i][j] > a[i][var]*a[var+1][j] + smoke[i][var] + smoke[var+1][j]){
						smoke[i][j] = a[i][var]*a[var+1][j] + smoke[i][var] + smoke[var+1][j];
						a[i][j] = (a[i][var] + a[var+1][j])%100;
					}
				}
				i++;j++;
			}
		}
		cout<<smoke[0][n-1]<<endl;
	}
	return 0;
}
