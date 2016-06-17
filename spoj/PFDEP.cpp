//Template

//Includes
#include <vector> 
#include <queue>
#include <map> 
#include <set>
#include <stack>
#include <list>
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
#include <functional>
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

vector<vector<int> > g(105);
bool visited[105];

void topologicalsort(int v,stack<int> &s){
	visited[v] = true;
	vector<int>::iterator it = g[v].begin();
	while(it!=g[v].end()){
		if(!visited[*it]){
			topologicalsort(*it,s);
		}
		it++;
	}
	s.push(v);
	return;
}



int main(){
	int n,r,i,k,a,b;
	fi(n);fi(r);
	rep(i,r){
		fi(a);fi(k);
		while(k--){
			fi(b);
			g[b-1].pb(a-1);
		}
	}
	for(i=0;i<n;i++){
		sort(g[i].begin(),g[i].end(),greater<int>());
	}
	stack<int> s;
	for(i=n-1;i>=0;i--){
		if(!visited[i])
			topologicalsort(i,s);
	}
	while(!s.empty()){
		printf("%d ",s.top()+1);
		s.pop();
	}pn;
	return 0;
}