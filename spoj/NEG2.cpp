#include <iostream>
#include <cmath>

using namespace std;


int main(){
	int n,i=0,j;
	cin>>n;
	int a[1000]={0};
	if(n!=0){
		while(n){
			if(n>0){
				a[i++]=n%2;
				n = -(n/2);
			}
			else{
				n = -n;
				a[i++]=n%2;
				n = ceil(n/2.0);
			}
		}
		for(j=i-1;j>=0;j--)
			cout<<a[j];
	}
	else 
		cout<<0;
	cout<<endl;
	return 0;
}