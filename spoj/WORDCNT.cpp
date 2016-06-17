#include <iostream>
#include <cstdio>
#include <math.h>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
#define fi(n) scanf("%d",&n)
using namespace std;

int main(){
	int t,gmax,lmax,prevl,i;
	string str;
	scanf("%d\n",&t);
	while(t--){
		getline(cin,str);
		gmax = 0 ; lmax = 0;prevl=0;
		string word;
		stringstream ss(str);
		while(ss>>word){
			if(word.length()==prevl)
				lmax ++;
			else{
				lmax = 1;
				prevl = word.length();
			}
			if(lmax > gmax)
				gmax = lmax;
		}
		cout<<gmax<<endl;
	}
	return 0;
}