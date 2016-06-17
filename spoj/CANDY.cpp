//Template

//Includes
#include <vector> 
#include <queue>
#include <map> 
#include <set>
#include <list>
#include <stack>
#include <utility> //Pair
#include <algorithm>
#include <sstream> // istringstream>> ostring stream<<
#include <iostream> 
#include <iomanip> 
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (4) << f << endl; Prints x.xxxx
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include <climits>
using namespace std;

//M lazy ;)
typedef long long int lli;
typedef vector <int> vi;
typedef pair< int ,int > pii;
typedef istringstream iss;
typedef ostringstream oss;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz size()
#define ln length()
#define sqr(x) (x)*(x)
#define rep(i,n) for(i=0;i<n;i++)
#define fu(i,a,n) for(i=a;i<=n;i++)
#define fd(i,n,a) for(i=n;i>=a;i--)
#define all(a)  a.begin(),a.end() 
#define ESP (1e-9)
#define PI 3.1415926535897932384626433832795

#define fi(n) scanf("%d",&n)
#define fii(n) scanf("%lld",&n)
#define ci(n) cin >> n
#define fo(n) printf("%d",n)
#define foo(n) printf("%lld",n)
#define co(n) cout << n
#define ps printf(" ")
#define pn printf("\n")
#define dg(n,s); printf("%s %d",s,n)
#define imax numeric_limits<int>::max()
#define imin numeric_limits<int>::min()
#define lmax numeric_limits<ll>::max()
#define lmin numeric_limits<ll>::min()



int main(){
	int t,i;
	lli n,answer;
	fi(t);
	while(t--){
		fii(n);
		i=0; answer=1;
		while(n>answer)
			answer <<= 1;
		cout<<answer;
		if(answer==n)
			n -= answer;
		while(n){
			answer >>= 1;
			if(answer<=n){
				n -= answer;
				
			}
			i++;
		}
		cout<<" "<<i<<endl;
	}
	return 0;
}