#include <iostream>
#include <stdio.h>
#include <math.h>
#include <climits>
#include <functional>
#include <string>
#include <cstring>
#include <algorithm>
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

int fractional(string &str){
	int n,temp=0,i=0,num = 0;
	n = str.size();
	while(i<n && str[i]!='.') i++;
	i++;
	while(i<n){
		temp++;
		num = num*10 + (str[i]-'0');
		i++;
	}
	num = num*((int)pow(10,4-temp));
	return num;
}

int main(){
	int t,i;
	string str;
	int f;
	fi(t);
	while(t--){
		cin>>str;
		f = fractional(str);
		rep(i,1,10001){
			if((f*i)%10000==0)
				break;
		}
		fo(i);
	}
	return 0;
}