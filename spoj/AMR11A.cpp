#include <bits/stdc++.h>
#define fi(n) scanf("%d",&n)
#define fo(n) printf("%d",n)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define all(v) v.begin(),v.end()
#define it(i,v) __typeof(v.begin()) i;
#define set(a,val) memset(a,val,sizeof(a))
#define rep(i,a,b) for(__typeof(a) i = (a); i < (b) ; i++)
#define rev(i,a,b) for(__typeof(a) i = (a); i >= (b) ; i--)
#define lli long long int 
#define vi vector<int> 
#define pii pair< int ,int > 
#define iss istringstream 
#define oss ostringstream 
#define sqr(x) (x)*(x)
#define ESP (1e-9)
#define PI 3.1415926535897932384626433832795
#define ps printf(" ")
#define pn printf("\n")
using namespace std;

//compile command== g++ -std=c++11

int main(){
	std::ios::sync_with_stdio(false);
	int t,r,c;
	fi(t);
	while(t--){
		fi(r);fi(c);
		int a[r][c];
		rep(i,0,r)rep(j,0,c) fi(a[i][j]);
		int need[r][c];
		need[r-1][c-1]=(a[r-1][c-1]>0) ?0: 1-a[r-1][c-1];
		rev(i,r-2,0) need[i][c-1] = max(max(need[i+1][c-1]-a[i][c-1], 1-a[i][c-1]), 0);
		rev(j,c-2,0) need[r-1][j] = max(max(need[r-1][j+1]-a[r-1][j], 1-a[r-1][j]), 0);
		rev(i,r-2,0){
			rev(j,c-2,0){
				need[i][j] = min(max(max(need[i+1][j]-a[i][j], 1-a[i][j]), 0),  max(max(need[i][j+1]-a[i][j], 1-a[i][j]), 0));
			}
		}
		cout<<need[0][0]<<endl; 
	}
	return 0;
}