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

int main(){
	ios::sync_with_stdio(false);
    int t; cin>>t;
    string one,two;
    rep(i,0,t){
        cin>>one>>two;
        queue<pii> myq;
        pii m;
        int vis[8][8];
        fill(vis,-1);
        myq.push(mp(one[0]-'a',one[1]-'1'));
        vis[one[0]-'a'][one[1]-'1'] =0;
        while(!myq.empty()){
            m = myq.front(); myq.pop();
            if(m.X == two[0]-'a' && m.Y == two[1]-'1') break;
            if(m.X+1<8 && m.Y+2<8 && vis[m.X+1][m.Y + 2]==-1) vis[m.X+1][m.Y + 2] = vis[m.X][m.Y] + 1, myq.push(mp(m.X+1,m.Y + 2));
            if(m.X+1<8 && m.Y >=2 && vis[m.X+1][m.Y - 2]==-1) vis[m.X+1][m.Y - 2] = vis[m.X][m.Y] + 1, myq.push(mp(m.X+1,m.Y - 2));
            if(m.X >=1 && m.Y+2<8 && vis[m.X-1][m.Y + 2]==-1) vis[m.X-1][m.Y + 2] = vis[m.X][m.Y] + 1, myq.push(mp(m.X-1,m.Y + 2));
            if(m.X >=1 && m.Y >=2 && vis[m.X-1][m.Y - 2]==-1) vis[m.X-1][m.Y - 2] = vis[m.X][m.Y] + 1, myq.push(mp(m.X-1,m.Y - 2));
            if(m.X+2<8 && m.Y+1<8 && vis[m.X+2][m.Y + 1]==-1) vis[m.X+2][m.Y + 1] = vis[m.X][m.Y] + 1, myq.push(mp(m.X+2,m.Y + 1));
            if(m.X+2<8 && m.Y >=1 && vis[m.X+2][m.Y - 1]==-1) vis[m.X+2][m.Y - 1] = vis[m.X][m.Y] + 1, myq.push(mp(m.X+2,m.Y - 1));
            if(m.X >=2 && m.Y+1<8 && vis[m.X-2][m.Y + 1]==-1) vis[m.X-2][m.Y + 1] = vis[m.X][m.Y] + 1, myq.push(mp(m.X-2,m.Y + 1));
            if(m.X >=2 && m.Y >=1 && vis[m.X-2][m.Y - 1]==-1) vis[m.X-2][m.Y - 1] = vis[m.X][m.Y] + 1, myq.push(mp(m.X-2,m.Y - 1));
        }
        cout<<vis[two[0]-'a'][two[1]-'1']<<endl;
    }
	return 0;
}
