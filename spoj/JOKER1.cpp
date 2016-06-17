#include <iostream>
#include <algorithm>
#define M 1000000007
#define lli long long int
using namespace std;

int main(){
	int t,n,i;
	lli result;
	cin>>t;
	while(t--){
		cin>>n;
		result =1;
		int a[n];
		for(i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n);
		for(i=0;i<n;i++){
			result = (result*(a[i]-i))%M;
			if(result < 0)
				result = 0;
		}
		cout<<result<<endl;
	}
	cout<<"KILL BATMAN\n";
	return 0;
}