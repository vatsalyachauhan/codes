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
	int n,ans;
	fi(n);
	if(n==0){
		printf("1\n0\n");
	}
	else{
		if(n%10){
			printf("1\n%d\n",n%10);

		}
		else{
			printf("2\n");
		}
	}
	return 0;
}