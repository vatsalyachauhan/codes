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
	int n;
	string str;
	set<string> :: iterator it;
	while(scanf("%d",&n)==1){
		set<string> myset;
		rep(i,0,n){
			cin>>str;
			it = myset.find(str);
			if(it == myset.end())
				myset.insert(str);
			else
				myset.erase(it);
		}

		cout<<((myset.size())?"first":"second")<<" player"<<endl;
	}
	return 0;
}

