#include <iostream>
#include <cstdio>
#include <math.h>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <sstream>
#include <stdlib.h>
#define fi(n) scanf("%d",&n)
using namespace std;

int primes[1000000];
int psize;

int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}

void markMultiples(bool arr[], int a, int n)
{
    int i = 2, num;
    while ( (num = i*a) <= n )
    {
        arr[ num-1 ] = 1;
        ++i;
    }
    return;
}
 
void SieveOfEratosthenes(int n)
{
    if (n >= 2)
    {
        bool arr[n];
        memset(arr, 0, sizeof(arr));
 
        for (int i=1; i<n; ++i)
        {
            if ( arr[i] == 0 )
            {
                primes[psize++]=i+1;
                markMultiples(arr, i+1, n);
            }
        }
    }
    return;
}

int getfactors(int &num,int j){
	int count=0;
	while(num % primes[j] == 0){
		count++;
		num /= primes[j];
	}
	return count+1;
}

int main(){
	int t,a,b,ans,temp,j;
	SieveOfEratosthenes(1000000);
	fi(t);
	while(t--){
		fi(a);fi(b);
		temp = gcd(a,b);
		ans = 1; j =0;
		while(temp!=1){
			ans *= getfactors(temp,j++);
		}
		printf("%d\n",ans);
	}
	return 0;
}