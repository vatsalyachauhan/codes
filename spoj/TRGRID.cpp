#include <iostream>
using namespace std;

int main(){
	int n,r,c,count,R,C;
	cin>>n;
	bool temp;
	char ch;
	while(n--){
		cin>>r>>c;
		count=0;
		if(r%2)
			R=1;
		else
			R=2;

		if(c%2)
			C=1;
		else
			C=2;
		if(r<=c){
			if(R==1)
				ch = 'R';
			else
				ch = 'L';
		}
		else{
			if(C==1)
				ch = 'D';
			else
				ch = 'U';
		}
		
		
		cout<<ch<<endl;

	}
	return 0;
}