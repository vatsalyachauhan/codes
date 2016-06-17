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

int dp[2005][2005];

int main(){
	int t,n,m;
	fi(t);
	string s1,s2;
	while(t--){
		cin>>s1>>s2;
		n = s1.size(), m = s2.size();
		rep(i,0,n+1) dp[i][0]=i;
		rep(i,0,m+1) dp[0][i]=i;
		rep(i,1,n+1)rep(j,1,m+1){
			if(s1[i-1]==s2[j-1])
				dp[i][j] = dp[i-1][j-1];
			else
				dp[i][j] = 1+ min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
		}
		cout<<dp[n][m]<<endl;
	}
	return 0;
}