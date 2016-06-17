#include <iostream>
#include <cmath>
using namespace std;

int max(int a,int b){
	return a>b?a:b;
}

int main(){
	int a,b,c,d,p,q,r,s,m,t1,t2,t3,t4;
	cin>>a>>b>>c>>d>>p>>q>>r>>s;
	while(a!=-1 &&b !=-1 && c!=-1 && d!=-1 && p!=-1 && q!=-1 && r!=-1 && s!=-1){
		t1 = ceil((a*1.0)/p);
		t2 = ceil((b*1.0)/q);
		t3 = ceil((c*1.0)/r);
		t4 = ceil((d*1.0)/s);
		m = max(max(t1,t2),max(t3,t4));
		cout<<m*p-a<<" "<<m*q-b<<" "<<m*r-c<<" "<<m*s-d<<endl;
		cin>>a>>b>>c>>d>>p>>q>>r>>s;
	}
	return 0;
}