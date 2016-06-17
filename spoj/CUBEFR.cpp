#include <iostream>
#include <cstdio>
#include <math.h>
#include <vector>
#include <queue>
#include <string.h>
#include <cstdlib>
#define fi(n) scanf("%d",&n)
using namespace std;

int primes[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
int positions[1000100]={0};

void markMultiples(int a, int n)
{
    int i = 1, num;
    while ( (num = i*a) <= n )
    {
        positions[ num ] = -1;
        ++i;
    }
}
 
void SieveOfEratosthenes(int n)
{	
	positions[0]=-1;
	positions[1]=1;
	int i;
    for (i=0; i<26; ++i)
    {   
    	int temp = primes[i]*primes[i]*primes[i];
        markMultiples(temp, n);
    }
    int count = 1;
    for(i=2;i<1000100;i++){
    	if(positions[i]==0){
    		count++;
    		positions[i] = count;
    	}
    }
    return;
}
 
int main(){
	int t,temp,i;
	SieveOfEratosthenes(1000100);
	fi(t);
	for(i=1;i<=t;i++){
		fi(temp);
		if(positions[temp] != -1)
			printf("Case %d: %d\n",i,positions[temp]);
		else
			printf("Case %d: Not Cube Free\n",i);
	}
	return 0;
}