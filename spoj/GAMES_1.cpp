#include <bits/stdc++.h>
#define fi(n) scanf("%d",&n)
#define fo(n) printf("%d\n",n)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define all(v) v.begin(),v.end()
#define it(i,v) __typeof(v.begin()) i;
#define set(a,val) memset(a,val,sizeof(a))
#define rep(i,a,b) for(i = (a); i < (b) ; i++)
#define rev(i,a,b) for(__typeof(a) i = (a); i >= (b) ; i--)
#define lli long long int
using namespace std;

int digits;
int num;

void fractional(string &str){
	int n,i=0;
	num = 0; digits = 0;
	n = str.size();
	while(i<n && str[i]!='.') i++;
	i++;
	while(i<n){
		digits++;
		num = num*10 + (str[i]-'0');
		i++;
	}
	return;
}

int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}

int main(){
	int t,i;
	string str;
	fi(t);
	while(t--){
		cin>>str;
		fractional(str);
		printf("%d\n",(int)(pow(10,digits)/gcd(pow(10,digits),num)));
	}
	return 0;
}