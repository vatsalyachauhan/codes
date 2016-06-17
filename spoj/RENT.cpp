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
#define ci(n) cin >> n
#define fo(n) printf("%d",n)
#define co(n) cout << n
#define ps printf(" ")
#define pn printf("\n")
#define dg(n,s); printf("%s %d",s,n)
#define imax numeric_limits<int>::max()
#define imin numeric_limits<int>::min()
#define lmax numeric_limits<ll>::max()
#define lmin numeric_limits<ll>::min()
#define pint pair< int , pii >
lli answer[2000100];

lli max(lli a,lli b){
	return a>b?a:b;
}


int main(){
	int t,n,a,b,c,i,size,index;
	lli temp;
	fi(t);
	while(t--){
		fi(n);
		set<pint > s;
		rep(i,n){
			fi(a);fi(b);fi(c);
			s.insert(mp(b+a,mp(a,c)));
		}
		set<pint >::reverse_iterator rit;
		set<pint >::iterator it;
		rit = s.rbegin();
		it = s.begin();
		size = rit->first;
		for(i=1;i<it->first;i++){
			answer[i]=0;
		}
		answer[i] = (it->second).second;
		it++;
		while(it!=s.end() && it->first == i){
			temp=max(answer[i-1],answer[((it->second).first-1)<0?0:((it->second).first-1)]+(it->second).second);
			if(answer[i]<temp)
				answer[i] = temp;
			it++;
		}
		i++;
		for(;i<=size;i++){
			if(it->first == i){
				answer[i]=max(answer[i-1],answer[((it->second).first-1)<0?0:((it->second).first-1)]+(it->second).second);
				it++;
				while(it!=s.end() && it->first == i){
					temp=max(answer[i-1],answer[((it->second).first-1)<0?0:((it->second).first-1)]+(it->second).second);
					if(answer[i]<temp)
						answer[i] = temp;
					it++;
				}
			}
			else
				answer[i]=answer[i-1];
		}
		
		printf("\n%lld\n",answer[size]);
	}
	return 0;
}