#include <iostream>
#include <cstdio>
#include <algorithm>

#define fi(n) scanf("%d",&n)
#define fo(n) printf("%d",n)
#define pn printf("\n")
#define ps printf(" ")

using namespace std;

int abc[1000010] = {0};
int def[1000010] = {0};

int main(){
	int i,n,j,k,p,q;
	fi(n);
	int s[n];
	for(i=0;i<n;i++)
		fi(s[i]);

	p = 0;

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			for(k=0;k<n;k++){
				abc[p++] = s[i]*s[j]+s[k];
			}
		}
	}

	q = 0;

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			for(k=0;k<n;k++){
				if(s[i])
					def[q++] = s[i]*(s[j]+s[k]);
			}
		}
	}

	sort(abc,abc+p);
	sort(def,def+q);
	i=0;j=0;
	int sol=0;
	while(i<p && j<q){
		while (i < p && j < q && abc[i] != def[j]) {
            if (abc[i] < def[j]) ++i;
            else ++j;
        }
        if (i == p || j == q) break;
        
        int val = abc[i], tmp_sol = 0;
        while (i < p && abc[i] == val) { ++tmp_sol; ++i; }
        int tmp_sol2 = 0;
        while (j < q && def[j] == val) { ++tmp_sol2; ++j; }
        sol += tmp_sol*tmp_sol2;
	}
	fo(sol);pn;
}