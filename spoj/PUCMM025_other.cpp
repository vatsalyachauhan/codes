#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<map>
#include<queue>
#include<stack>
#include<vector>
using namespace std;

#define	gi(a)		scanf("%d",&a)
#define	Int(a)		int a;gi(a);
#define Pair		pair <int,int>
#define mp		make_pair
#define ll		long long
#define INF		2147483647
#define clear(a,b)	memset(a,b,sizeof(a))

int main(){
	char N[250];
	while(scanf("%s",N)!=EOF){
		int no[10]={0};
		int i,j,t=0,ct=0;
		for(i=0;N[i]!='\0';i++){
			no[N[i]-'0']++;
			t++;
		}
		for(i=1;i<10;i++){
			if(no[i]>0){
				int s1=0;
				for(j=0;j<t;j++){
					s1=(s1*10)+(N[j]-'0');
					if(s1>=i)
						s1=s1%i;
				}
				if(s1==0)	ct=ct+no[i];
			}
		}
		printf("%d\n",ct);
	}
	return 0;
}