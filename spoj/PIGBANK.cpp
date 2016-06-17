#include <iostream>
#include <cstdio>
#include <limits.h>
#define fi(n) scanf("%d",&n)
#define lli long long int
using namespace std;

int min(int a,int b){
	return a>b?b:a;
}

int main(){
	int t,e,w,i,j,n,temp;
	cin>>t;
	while(t--){
		cin>>e>>w;
		w = w-e;
		cin>>n;
		int data[2][n];
		for(i=0;i<n;i++){
			cin>> data[0][i]>>data[1][i];
		}
		long long int dp[n+1][w+1];
		for(i=0;i<w+1;i++) dp[0][i] = INT_MAX;
		for(i=0;i<n+1;i++) dp[i][0] = 0;

		for(i=1;i<n+1;i++){
			for(j=1;j<w+1;j++){
				if (i == 1 and j < data[1][i])
				{
					dp[i][j] = INT_MAX;
					//keep[i][j] = 0;
				}
				else if (i == 1)
				{
					dp[i][j] = data[0][i] + dp[i][j - data[1][i]];
					//keep[i][j] = 1;
				}
				else if (j < data[1][i])
				{
					dp[i][j] = dp[i - 1][j];
					//keep[i][j] = 0;
				}
				else
				{
					dp[i][j] = min(dp[i - 1][j],data[0][i] + dp[i][j - data[1][i]]);
					//keep[i][j] = 1;
				}
			}
		}
		if(dp[n][w]>=INT_MAX)
			printf("This is impossible.\n");
		else
			printf("The minimum amount of money in the piggy-bank is %d.\n",dp[n][w]);
	}
	return 0;
}