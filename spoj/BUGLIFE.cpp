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
#define 	fill(a,val) 	memset(a,val,sizeof(a))
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
#define 	MOD 		1000000007
#define     X 			first
#define     Y 			second

bool visited[2005];
int color[2005];


bool dfs(vvi &g, int root,int root_color){
    bool ans = false;
    tr(g[root],itr){
        if(visited[*itr] && color[*itr]==root_color)
            return true;
        else if(!visited[*itr]){
            visited[*itr] = true;
            color[*itr] = 1- root_color;
            ans = ans || dfs(g,*itr,1-root_color);
        }
    }
    return ans;
}

int main(){
	ios::sync_with_stdio(false);
    int t,n,e,u,v,k;
    cin>>t;
    rep(i,1,t+1){
        cin>>n>>e;
        vvi graph(n+1);
        fill(visited,0);
        rep(j,0,e){
            cin>>u>>v;
            graph[u].pb(v);
            graph[v].pb(u);
        }
        bool bug = false;
        k = 1;
        while(!bug && k<=n){
            if(!visited[k]){
                visited[k] = true;
                color[k] = 0;
                bug = bug || dfs(graph, k,0);
            }
            k++;
        }
        cout<<"Scenario #"<<i<<":\n"<<(bug? "Suspicious bugs found!":"No suspicious bugs found!")<<endl;
    }
	return 0;
}

