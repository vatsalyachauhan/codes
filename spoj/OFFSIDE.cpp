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
	int a,d,mina,num;
	fi(a);fi(d);
	int bb[50];
	int aa[50];

	while(!(a==0 && d==0)){
		mina = INT_MAX;
		rep(i,0,a){
			fi(aa[i]);
		}
		sort(aa,aa+a);
		rep(i,0,d){
			fi(bb[i]);
		}
		sort(bb,bb+d);
		if(aa[0]<bb[1])
			cout<<'Y'<<endl;
		else
			cout<<'N'<<endl;
		fi(a);fi(d);
	}
	return 0;
}