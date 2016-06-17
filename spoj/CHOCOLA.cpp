#include <iostream>
#include <cstdio>
#include <math.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#define pii pair<int,int>
#define fi(n) scanf("%d",&n)
using namespace std;

int main(){
	int t,m,n,i,hordone,verdone;
	long long int answer;
	fi(t);
	while(t--){
		hordone = 1; verdone = 1; answer = 0;
		fi(m);fi(n);
		int hor[n-1];
		int ver[m-1];
		vector<pii> maps;
		for(i=0;i<m-1;i++){
			fi(ver[i]);
			maps.push_back(pair<int,int>(ver[i],1));
		}
		for(i=0;i<n-1;i++){
			fi(hor[i]);
			maps.push_back(pair<int,int>(hor[i],0));
		}

		sort(maps.begin(),maps.end());
		vector<pii>::reverse_iterator it;
		it = maps.rbegin();
		
		while(it!=maps.rend()){
			if(it->second){
				answer = answer + (it->first)*hordone;
				verdone++;
			}
			else{
				answer = answer + (it->first)*verdone;
				hordone++;
			}
			it++;
		}
		printf("%lld\n",answer);
		
	}
	return 0;
}