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
#define dg(n,s); printf("%s %d",s,n)
#define imax numeric_limits<int>::max()
#define imin numeric_limits<int>::min()
#define lmax numeric_limits<ll>::max()
#define lmin numeric_limits<ll>::min()
using namespace std;

//compile command== g++ -std=c++11


lli gbl[5001];

lli func(string str,int low,int high){
	int f,s,m,t,t1,t2;
 
	if(low == high){
		gbl[low]=1; return 1;
	}
	else if (low+1 == high){
		f = str[low]-'0';
		s = str[high]-'0';
		m = 10*f +s;
		if(m<27 && s!=0){
			gbl[low]=2; return 2;
		}
		else{
			gbl[low] =1; return 1;
		}
	}
	else{
		f = str[low]-'0';
		s = str[low+1]-'0';
		t = str[low+2]-'0';
		m = 10*f +s;
		if(s==0){
			gbl[low] = gbl[low+2]==-1 ? func(str,low+2,high) : gbl[low+2];
			return gbl[low];
		}
		else if(t==0 || m>26){
			gbl[low] = gbl[low+1]==-1 ? func(str,low+1,high) : gbl[low+1];
			return gbl[low];
		}
		else{
			t1 = gbl[low+1]==-1?func(str,low+1,high):gbl[low+1];
			t2 = gbl[low+2]==-1?func(str,low+2,high):gbl[low+2];
			gbl[low]=t1+t2;
			return  gbl[low];
		}
	}
}
 
int main(){
	std::ios::sync_with_stdio(false);
	int n;
	string str;
	cin>>str;
	n = str.size();
	while(n>1 || str[0]!='0'){
		set(gbl,-1);
		cout<<func(str,0,n-1)<<endl;
		cin>>str;
		n = str.size();
	}
	return 0;
} 