#include <stdio.h>
#include <iostream>

#define fi(n) scanf("%d",&n)
#define fo(n) printf("%d",n)
#define pn printf("\n")
#define ps printf(" ")

using namespace std;

int main(){
	int t,n,m,i,count,d,h;
	fi(t);
	while(t--){
		count = 0;
		fi(n);fi(m);fi(d);
		for(i=0;i<n;i++){
			fi(h);
			if(h%d)
				count += h/d;
			else
				count += h/d -1;
		}
		if(count>=m)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}