#include <iostream>
#include <cstdio>
#include <algorithm>
#define fi(n) scanf("%d",&n)
#define flli(n) scanf("%lld",&n)
#define fo(n) printf("%d",n)
using namespace std;

bool F(int dist,int *pos,int n,int c){
	int lastpos = pos[0];
	int cows = 1,i;
	for(i=1;i<n;i++){
		if(pos[i]-lastpos>=dist){
			lastpos = pos[i];
			if(++cows == c)
				return true;
		}
	}
	return false;
}


int max_dist(int n,int *pos,int c){
	int start = 0,end = pos[n-1]-pos[0]+1,mid;
	while(end-start>1){
		mid = (start+end)>>1;
		(F(mid,pos,n,c)?start:end) = mid;
	}
	return start;
}

int main(){
	int t,i,n,c;
	fi(t);
	while(t--){
		fi(n);fi(c);
		int pos[n];
		for(i=0;i<n;i++)
			fi(pos[i]);
		sort(pos,pos+n);
		cout<<max_dist(n,pos,c)<<endl;
	}
	return 0;
}