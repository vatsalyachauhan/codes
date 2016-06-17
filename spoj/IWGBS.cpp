#include <iostream>
#include <algorithm>
#include <string>
#define M 1000000007
#define lli long long int
using namespace std;

string summ(string &temp1,string &temp2){
	int c=0,i=0;
	string result;
	int minsize = (temp1.size()>temp2.size())?temp2.size():temp1.size();
	int maxsize = (temp1.size()<temp2.size())?temp2.size():temp1.size();
	while(i<minsize){
		result += ((temp1[i]-'0')+(temp2[i]-'0')+c)%10 + '0';
		c = ((temp1[i]-'0')+(temp2[i]-'0')+c)/10;
		i++;
	}
	string &temp3 = (temp1.size()==minsize)?temp2:temp1;
	while(i<maxsize){
		result += ((temp3[i]-'0')+c)%10 + '0';
		c = ((temp3[i]-'0')+c)/10;
		i++;
	}
	if(c>0){
		result += '1';
	}
	return result;
}


int main(){
	int n,size=2;
	cin>>n;
	string temp1,temp2,result;
	temp1 = "2";
	temp2 = "3";
	if(n==0){
		cout<<0<<endl;
	}
	else if(n==1){
		cout<<2<<endl;
	}
	else if(n==2){
		cout<<3<<endl;
	}
	else{
		while(size<n){
			result = summ(temp1,temp2);
			temp1 = temp2;
			temp2 = result;
			size++;
		}
		string::reverse_iterator it;
		for(it=result.rbegin();it!=result.rend();it++){
			cout<<*it;
		}cout<<"\n";
	}
	return 0;
}