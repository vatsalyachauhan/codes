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
#define 	fi(n) 		scanf("%d",&(n))

#define 	iss 		istringstream
#define 	oss 		ostringstream
#define 	sqr(x) 		(x)*(x)
#define 	ESP 		(1e-9)
#define 	PI 			3.1415926535897932384626433832795
#define 	MOD 		1000000007
#define     X 			first
#define     Y 			second
#define     pn          cout<<endl

//g++ -std=c++11 your_file.cpp -o your_program

int BLOCK = 0,answer=0;
int ans[200005], cnt[1000005],a[30005];

struct query{
	int L,R,I;
};

bool cmp(const query &a, const query &b){
	if(a.L/BLOCK != b.L/BLOCK) 
		return a.L/BLOCK < b.L/BLOCK;
	else
		return a.R < b.R;
}

void add(int pos){
	cnt[a[pos]]++;
	if(cnt[a[pos]]==1) answer++;
}

void remove(int pos){
	cnt[a[pos]]--;
	if(cnt[a[pos]]==0) answer--;
}

int main(){
	int n,q,l=0,r=0,L,R;
	fi(n);
	BLOCK = sqrt(n);
	rep(i,0,n) fi(a[i]);
	fi(q);
	vector<query> v(q);
	rep(i,0,q){
		fi(v[i].L); fi(v[i].R);
		v[i].L--; v[i].R--; v[i].I = i;
	}
	sort(v.begin(),v.end(), cmp);
	rep(i,0,q){
		L = v[i].L, R = v[i].R;
		while(L<l)
			add(--l);
		while(R>r)
			add(r++);
		while(L>l)
			remove(l++);
		while(R<r)
			remove(--r);

		ans[v[i].I] = answer;
	}
	rep(i,0,q)
		printf("%d\n",ans[i]);
	return 0;
}