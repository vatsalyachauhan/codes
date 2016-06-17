#include <iostream>
using namespace std;

int minm(int a,int b){
	return a>b?b:a;
}

int main(){
	int n,m,i,j,min,num;
	cin>>n>>m;
	int a[n][m];
	for(j=0;j<m;j++)
		cin>>a[0][j];

	for(i=1;i<n;i++){
		for(j=0;j<m;j++){
			cin>>a[i][j];
			min = a[i-1][j];
			if(j-1>=0)
				min = minm(min,a[i-1][j-1]);
			if(j+1<m)
				min = minm(min,a[i-1][j+1]);
			a[i][j] += min;
		}
	}
	min = a[n-1][0];
	for(j=1;j<m;j++)
		if(min > a[n-1][j])
			min = a[n-1][j];

	cout<<min<<endl;
}