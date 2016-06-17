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

using namespace std;

int main(){
	int t,base,n,used;
	lli ans,mul;
	string str;
	fi(t); t++;
	rep(i,1,t){
		map<char,int> mymap;
		base = 0;
		ans = 0;
		mul = 1;
		used = -1;

		cin>>str;
		n = str.size();
		rep(j,0,n) mymap[str[j]] = -1;
		base = mymap.size();
		if(base == 1)
			base = 2;
		
		rep(j,1,n) mul = mul*base;


		mymap[str[0]] = 1; ans = mul;

		rep(j,1,n){
			if(mymap[str[j]]==-1){
				used++; if(used==1) used++;
				mul /=base;
				mymap[str[j]] = used;
				ans += mymap[str[j]]*mul;
			}
			else{
				mul /=base;
				ans += mymap[str[j]]*mul;
			}
		}

		cout<<"Case #"<<i<<": "<<ans<<endl;
	}
	return 0;
}