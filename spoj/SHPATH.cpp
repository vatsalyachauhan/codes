#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

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

const int INF = 0x7f7f7f7f;

int d[10010];

int dijkstra(vector<vector<pii> > &G, int start, int target) {
    int u, v, i, c, w;
    priority_queue< pii, vector< pii >, greater< pii > > Q;

    fill(d,0x7f);
    Q.push(pii(0, start));
    d[start] = 0;

    while(!Q.empty()) {
        u = Q.top().second; // node
        c = Q.top().first; // node cost so far
        Q.pop(); // remove the top item.

        if(d[u] < c) continue;
        if(u==target) return c;
        for(i = 0; i < G[u].size(); i++) {
            v = G[u][i].first; // node
            w = G[u][i].second; // edge weight

            if(d[v] > d[u] + w) {
                d[v] = d[u] + w;
                Q.push(pii(d[v], v));
            }
        }
    }
    return INF;
}

int main() {
    ios::sync_with_stdio(false);

    int n, e, u, v, w, T,p,q;
    string name1,name2;
    cin>>T;
    rep(i,0,T){
        cin>>n;
        vector<vector<pii> > G(n+1);
        map<string,int> mymap;
        rep(j,0,n){
            cin>>name1; mymap[name1] = j+1;
            cin>>p;
            rep(k,0,p){
                cin>>v>>w;
                G[j+1].push_back(pii(v, w));
                G[v].push_back(pii(j+1, w));
            }
        }
        cin>>q;
        while(q--){
            cin>>name1>>name2;
            cout<<dijkstra(G,mymap[name1], mymap[name2])<<endl;
        }
    }
    return 0;
}
