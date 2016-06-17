#include <iostream>
#define lli long long int
using namespace std;

lli f(lli n){
	lli result = n,i=1;
	while(n){
		n >>= 1;
		result += i*n;
		i <<= 1;
	}
	return result;
}


int main(){
	lli a,b;
	cin>>a>>b;
	cout<<f(b)-f(a-1)<<endl;
	return 0;
}