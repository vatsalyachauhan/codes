#include <iostream>
#include <queue>

using namespace std;

int a[10000]={0};

int main(){
	int n,i,j,m,temp,count=0;
	cin>>n;
	int friends[101]={0};
	for(i=0;i<n;i++){
		cin>>friends[i];
		cin>>m;
		for(j=0;j<m;j++){
			cin>>temp;
			a[temp]=1;
		}
	}
	for(j=0;j<i;j++){
		a[friends[j]]=0;
	}
	for(i=0;i<10000;i++)
		if(a[i])
			count++;

	cout<<count<<endl;
}