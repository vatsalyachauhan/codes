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
#define PII pair<int,int>

using namespace std;



int main(){
	int h,w,a,b,ans;
	fi(h);fi(w);
	while(!(h==0 && w==0)){
		string str[h];
		vector<vector<int> > g(h);
		rep(i,0,h) cin>>str[i];
		rep(i,0,h) rep(j,0,w){
			rep(s,-1,2) rep(t,-1,2){
				a = a+s; b = b+t;
				if(a>=0 && a<h && b>=0 && b<w && s*t!=0)
					if(str[a][b] - str[i][j]==1)
						g[i*w+j+1].pb(a*w+b+1);
			}
		}
		rep

		fi(h);fi(w);
	}
	return 0;
}