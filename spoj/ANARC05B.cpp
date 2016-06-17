#include <iostream>
#include <stdio.h>

#define fi(n) scanf("%d",&n)
#define fo(n) printf("%d",n)

using namespace std;


int maxm(int a,int b){
	return a>b?a:b;
}

int main(){
	int n,m,i,j,sum1,sum2,temp,max;
	
	while(1){
		int a[10010];
		int b[10010];

		fi(n);
		if(n==0)
			break;
		for(i=0;i<n;i++)
			fi(a[i]);

		fi(m);
		for(j=0;j<m;j++)
			fi(b[j]);

		sum1 = 0; sum2 = 0;
		i=0;j=0;
		while(i<n && j<m){
			if(a[i]<b[j]){
				sum1 += a[i]; i++;
			}
			else if(a[i]>b[j]){
				sum2 += b[j]; j++;
			}
			else{
				sum1 += a[i];
				sum2 += b[j]; 
				sum1 =  maxm(sum1,sum2);
				sum2 = sum1;
				i++;j++;
			}
		}

		while(i<n)
			sum1 += a[i++];
		while(j<m)
			sum2 += b[j++];

		cout<<maxm(sum1,sum2)<<endl;
	}
	return 0;
}