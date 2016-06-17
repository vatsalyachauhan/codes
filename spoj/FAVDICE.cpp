#include <iostream>
#include <stdio.h>

using namespace std;


int main (){
	int n,i,num,temp;
	float sum;
	cin>>n;
	while(n--){
		cin>>num;
		sum = 0;
		temp = num;
		while(temp){
			sum += (num*1.0)/temp;
			temp--;
		}
		printf("%.2f\n",sum);
	}
	return 0;
}