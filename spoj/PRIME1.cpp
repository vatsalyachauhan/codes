#include <iostream>
#include <stdio.h>
#include <math.h>
#include <climits>
#include <functional>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#define fi(n) scanf("%d",&n)
#define fo(n) printf("%d\n",n)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define all(v) v.begin(),v.end()
#define it(i,v) __typeof(v.begin()) i;
#define set(a,val) memset(a,val,sizeof(a))
#define rep(i,a,b) for(__typeof(a) i = (a); i < (b) ; i++)
#define rev(i,a,b) for(__typeof(a) i = (a); i >= (b) ; i--)

using namespace std;

int primes[3500];
int counts;
bool visited[31630];


void mark_multiples(int num){
	int i_num;
	i_num = num;
	while(i_num<=31629){
		visited[i_num] = true;
		i_num = i_num + num;
	}
	return;
}

void sieve(){
	int i;
	mark_multiples(2);
	primes[counts++] = 2;
	for(i=3;i<=31629;i=i+2){
		if(visited[i]==false){
			mark_multiples(i);
			primes[counts++] = i;
		}
	}
	return;
}

int main(){
	int t,m,n,i,j;
	bool flag;
	fi(t);
	sieve();
	while(t--){
		fi(m);fi(n);
		if(m<=2 && n>=2) {fo(2); m = 3;}
		if(m%2==0) m++;

		for(i=m;i<=n;i = i+2){
			flag = true;
			for(j=0;j<counts;j++){
				if(i==primes[j]){
					break;
				}
				if(i%primes[j]==0){
					flag = false; break;
				}
			}
			if(flag) fo(i);
		}
		printf("\n");
	}
	return 0;
}