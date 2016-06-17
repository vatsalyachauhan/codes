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


#define N 30010
#define l(x) (x << 1) + 1
#define r(x) (x << 1) + 2

struct node {
    lli val;
    inline void combine(const node & left, const node & right) {
        val = left.val + right.val;
    }
    node(){val = 0;}

} tree[N << 2], identity;

struct segmentTree {

    int n;
    node * T;

    void init(int m) {
        n = m;
        T = tree;
        build(0, 0, n - 1);
    }

    void build(int x, int l, int r) {
        if(l == r) {
            T[x].val = 1;
            return;
        }
        int m = (l + r) >> 1;
        build(l(x), l, m);
        build(r(x), m + 1, r);
        T[x].combine(T[l(x)], T[r(x)]);
    }

    //might need to add a value parameter here
    void updateRange(int x, int l, int r, int ql, int qr) {
        if(l == ql and r == qr) {
            tree[l].val = 0;
            return;
        }
        int m = (l + r) >> 1;
        if(qr <= m)
         updateRange(l(x), l, m, ql, qr);
        else if(ql > m)
         updateRange(r(x), m+1, r, ql, qr);
        else
        {
          updateRange(l(x), l, m, ql, m);
          updateRange(r(x), m + 1, r, m+1, qr);
        }
    }

    int queryRange(int x, int l, int r, int ql, int qr) {
        propagate(x, l, r);
        if(l == ql and r == qr) {
            return tree[x].val;
        }
        long long ret = 0;
        long long m = (l + r) >> 1;
        if(qr <= m)
          ret += queryRange(l(x), l, m, ql, qr);
        else if(ql > m)
          ret += queryRange(r(x), m + 1, r, ql, qr);
        else
        {
          propagate(x,l,r);
          ret += queryRange(l(x), l, m, ql, m) + queryRange(r(x), m + 1, r, m+1, qr);
        }
        return ret;
    }

    //add value parameter here
    void update(int ql, int qr) {
        updateRange(0, 0, n - 1, ql, qr);
    }

    int query(int ql, int qr) {
        return queryRange(0, 0, n - 1, ql, qr);
    }
};


int main(){
	ios::sync_with_stdio(false);
    int n,temp,q,l,r,k,K;
    vector<pii> my;
    cin>>n;
    segmentTree st;
    st.init(n);
    rep(i,0,n){
        cin>>temp; my.pb(mp(temp,i));
    }
    cin>>q;
    lli ans[q];
    vector<pii,pii> queries;
    rep(i,0,q){
        cin>>l>>r>>k;
        queries.pb(mp(mp(k,i),mp(l,r)));
    }
    sort(queries.begin(),queries.end());
    tr(queries,itr){
        while()
    }

	return 0;
}
