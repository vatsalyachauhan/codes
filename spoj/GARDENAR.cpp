#include <iostream>
#include <stdio.h>
#include <math.h>
#include <climits>
#include <functional>
#include <string>
#include <cstring>
#define fi(n) scanf("%d",&n)
#define fo(n) printf("%d",n)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define all(v) v.begin(),v.end()
#define it(i,v) __typeof(v.begin()) i;
#define set(a,val) memset(a,val,sizeof(a))
#define rep(i,a,b) for(__typeof(a) i = (a); i < (b) ; i++)
#define rev(i,a,b) for(__typeof(a) i = (a); i >= (b) ; i--)
#define sq(a) (a)*(a)

using namespace std;

int main(){
	int t,a,b,c;
	double c1,c2,c3,aa,bb;
	fi(t);
	while(t--){
		fi(a);fi(b);fi(c);
		c1 = sq(a)-sq(b);
		c2 = sq(a)+sq(b)-2*sq(c);
		c3 = 6*sq(a);
		aa = 3*c1+c2-c3;
		bb = 3*sq(c1) + sq(c2);
		bb = (sqrt(3)*(-aa+sqrt(sq(aa)-4*bb)))/16;
		printf("%.2lf\n",bb);
	}
	return 0;
}