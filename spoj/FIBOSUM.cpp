#include <iostream>
#include <cstdio>
#include <algorithm>
#define fi(n) scanf("%d",&n)
#define flli(n) scanf("%lld",&n)
#define fo(n) printf("%d",n)
#define lli long long int
#define num 1000000007
using namespace std;

void multiply(lli F[2][2], lli M[2][2]);
 
void power(lli F[2][2], lli n);

lli mod(lli a){
	return a%num;
}
/* function that returns nth Fibonacci number */
lli fib(lli n)
{
  lli F[2][2] = {{1,1},{1,0}};
  if (n == 0)
    return 0;
  power(F, n-1);
  return F[0][0];
}
 
/* Optimized version of power() in method 4 */
void power(lli F[2][2], lli n)
{
  if( n == 0 || n == 1)
      return;
  lli M[2][2] = {{1,1},{1,0}};
 
  power(F, n/2);
  multiply(F, F);
 
  if (n%2 != 0)
     multiply(F, M);
}
 
void multiply(lli F[2][2], lli M[2][2])
{
  lli x =  mod(mod(F[0][0]*M[0][0]) + mod(F[0][1]*M[1][0]));
  lli y =  mod(mod(F[0][0]*M[0][1]) + mod(F[0][1]*M[1][1]));
  lli z =  mod(mod(F[1][0]*M[0][0]) + mod(F[1][1]*M[1][0]));
  lli w =  mod(mod(F[1][0]*M[0][1]) + mod(F[1][1]*M[1][1]));
 
  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}


int main(){
	int t;
	lli n,m,ans;

	fi(t);
	while(t--){
		flli(n);flli(m);
		ans = fib(m+2)-fib(n+1);
		while(ans<0)
			ans += num;
		printf("%lld\n",mod(ans));
	}
	return 0;
}