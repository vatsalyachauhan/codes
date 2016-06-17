
#include <vector> 
#include <queue>
#include <map> 
#include <set>
#include <list>
#include <stack>
#include <algorithm>
#include <iostream> 
#include <iomanip> 
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <climits>
#include <iostream>
using namespace std;

#define PI (2*acos(0.0))


#define gravity 9.806

int main(){
	int t,i;
	float r,v,angle;
	cin>>t;
	for(i=0;i<t;i++){
		cin>>r>>v;
		angle = (asin((gravity*r)/(v*v)))*90.0/PI;
		if(r>((v*v)/gravity) || angle > 45.0)
			printf("Scenario #%d: -1\n",i+1);
		else
			printf("Scenario #%d: %.2f\n",i+1,angle);
	}
	return 0;
}