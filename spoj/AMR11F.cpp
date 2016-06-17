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
#define 	MOD 		1000000007
#define     X 			first
#define     Y 			second

int n,f;

inline int dist(pii &A, pii &B){
    if(A.X==B.X) return abs(A.Y-B.Y);
    return (A.Y-1)+(B.Y-1)+min(abs(A.X-B.X),n-abs(A.X-B.X));
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
    int T,m,q,bi,fi,bj,fj,t,tt;
    cin>>T;
    while(T--){
        cin>>n>>f>>m;
        vector<pii> nodes;
        int mat[310][310];
        rep(i,0,310)rep(j,0,310) {
            if(i==j) {mat[i][j] = 0;continue;}
            mat[i][j] = INT_MAX;
        }
        vector<pii> pos[n+1];

        while(m--){
            cin>>bi>>fi>>bj>>fj>>t;
            tt = nodes.size();
            nodes.pb(mp(bi,fi)); pos[bi].pb(mp(fi,tt));
            nodes.pb(mp(bj,fj)); pos[bj].pb(mp(fj,tt+1));
            mat[tt+1][tt] = mat[tt][tt+1] = min(min(t,mat[tt][tt+1]),dist(nodes[tt],nodes[tt+1]));
        }
        tt = nodes.size();
        rep(i,0,n){
            nodes.pb(mp(i+1,1)); pos[i+1].pb(mp(1,tt+i));
        }
        int loop = nodes.size();
        rep(k,0,loop)rep(i,0,loop)rep(j,0,loop){
            mat[i][j] = min(mat[i][j],dist(nodes[i],nodes[j]));
            if(mat[i][k]!=INT_MAX && mat[k][j]!=INT_MAX && mat[i][j]>mat[i][k]+mat[k][j])
                mat[i][j] = mat[i][k]+mat[k][j];
        }
        rep(i,1,n+1) sort(pos[i].begin(),pos[i].end());
        cin>>q;
        while(q--){
            cin>>bi>>fi>>bj>>fj;
            int ans = (bi==bj) ? abs(fi-fj) : (fi+fj-2 + min(abs(bi-bj),n-abs(bi-bj))) ;
            int temp;
            vector<pii>::iterator b1,b2,b3;
            b1 = lower_bound(all(pos[bi]),mp(fi,0)); b2 = lower_bound(all(pos[bj]),mp(fj,0));
            if(b1!=pos[bi].end() && b2!=pos[bj].end()){
                temp = mat[b1->second][b2->second];
                ans = min(ans, temp +  abs(b1->X - fi) + abs(b2->X - fj) );
            }
            if(b1!=pos[bi].end() && b2!=pos[bj].begin()){
                b2--;
                temp = mat[b1->second][b2->second];
                ans = min(ans, temp +  abs(b1->X - fi) + abs(b2->X - fj) );
                b2++;
            }
            if(b1!=pos[bi].begin() && b2!=pos[bj].end()){
                b1--;
                temp = mat[b1->second][b2->second];
                ans = min(ans, temp +  abs(b1->X - fi) + abs(b2->X - fj) );
                b1++;
            }
            if(b1!=pos[bi].begin() && b2!=pos[bj].begin()){
                b1--; b2--;
                temp = mat[b1->second][b2->second];
                ans = min(ans, temp +  abs(b1->X - fi) + abs(b2->X - fj) );
            }
            cout<<ans<<endl;
        }
    }
	return 0;
}
