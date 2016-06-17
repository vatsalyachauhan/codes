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

using namespace std;

int main(){
	int cnt0=0,n,survival_chances=0;
	string str;
	cin>>str;
	n = str.size();
	rep(i,0,n) if(str[i]=='0')cnt0++;
	rep(i,1,n) if(str[i-1]=='0' && str[i]=='0') survival_chances++;
	if(str[n-1]=='0' && str[0]=='0') survival_chances++;
	if(survival_chances*n==cnt0*cnt0) cout<<"EQUAL"<<endl;
	else if(survival_chances*n > cnt0*cnt0) cout<<"SHOOT"<<endl;
	else cout<<"ROTATE"<<endl;
	return 0;
}