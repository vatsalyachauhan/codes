#include <iostream>
#include <cstdio>
#define fi(n) scanf("%d",&n)
using namespace std;

int minm(int a,int b){
	return a>b?b:a;
}

int main(){
	int n,i,l,m,r,temp,nl,nm,nr,tests=0;
	scanf("%d",&n);

	while(n){
		tests++;
		fi(l);fi(m);fi(r);
		r = m+r;
		fi(nl);fi(nm);fi(nr);
		if(n>1){
			nl = m+nl;
			nm = nm+minm(m,minm(r,nl));
			nr = nr+minm(m,minm(nm,r));
			l = nl; m =nm; r = nr;
		}
		for(i=2;i<n;i++){
			fi(temp);
			nl = temp + minm(l,m);
			fi(temp);
			nm = temp + minm(minm(l,m),minm(r,nl));
			fi(temp);
			nr = temp + minm(m,minm(r,nm));
			l = nl; m = nm; r = nr;
		}
		printf("%d. %d\n",tests, m);
		scanf("%d",&n);
	}
	return 0;
}