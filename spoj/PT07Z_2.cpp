#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;

#define 	pb(x) 		push_back(x)
#define 	sz(a) 		int((a).size())
#define 	sortA(v)	sort(v.begin(), v.end())
#define 	sortD(v)	sort(v.begin(), v.end(), greater<auto>())
#define 	mp(x,y) 	make_pair(x,y)
#define 	all(v) 		v.begin(),v.end() //Don’t put the whole right-hand side of these macros into parentheses – that would be wrong!
#define 	it(i,v) 	__typeof(v.begin()) i;
#define 	set(a,val) 	memset(a,val,sizeof(a))
#define 	rep(i,a,b) 	for(__typeof(a) i = (a); i < (b) ; i++)
#define 	rev(i,a,b) 	for(__typeof(a) i = (a); i >= (b) ; i--)
#define 	tr(vec,it) 	for(__typeof(vec.begin()) it = vec.begin();it!=vec.end();++it)
#define 	present(container, element) (container.find(element) != container.end())
#define 	cpresent(container, element) (find(all(container),element) != container.end())
#define 	LL 			long long int

#define 	iss 		istringstream
#define 	oss 		ostringstream
#define 	sqr(x) 		(x)*(x)
#define 	ESP 		(1e-9)
#define 	PI 			3.1415926535897932384626433832795
#define 	ps 			printf(" ")
#define 	pn 			printf("\n")
#define 	MOD 		1000000007
#define     X 			first
#define     Y 			second

vi g[10010];
bool visited[10010];
int ans;
int dfs(int root){
    visited[root] = true;
    int M = 0,m = 0,x;
    tr(g[root],itr){
        if(!visited[*itr])
            x = dfs(*itr);
        if(x >= M) m = M, M = x;
        else if(x>m) m = x;
    }
    ans = max(ans,m+M);
    return M+1;
}
int main(){
	ios::sync_with_stdio(false);
	int n,u,v;
	cin>>n;
	rep(i,1,n){
        cin>>u>>v;
        g[u-1].pb(v-1);
        //g[v-1].pb(u-1);
	}
	dfs(0);
	cout<<ans<<endl;
	return 0;
}
