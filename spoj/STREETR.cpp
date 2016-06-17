#include <iostream>
#include <cstdio>
#include <math.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
#define pii pair<int,int>
#define fi(n) scanf("%d",&n)
using namespace std;

int func(int a,int b){
	return b?func(b,a%b):a;
}

int main(){
	int n,temp2,temp1,i,f,l,gcd,answer;
	fi(n);
	set<int> s;
	fi(f);
	temp1=f;
	for(i=1;i<n;i++){
		fi(temp2);
		s.insert(temp2-temp1);
		temp1=temp2;
	}
	l=temp2;
	set<int>::iterator it=s.begin();
	gcd = (*it);
	it++;
	while(it!=s.end()){
		gcd = func(gcd,*it);
		it++;
	}
	answer = ((l-f)/gcd)+1-n;
	printf("%d\n",answer);
	return 0;
}