#include <iostream>
#include <stdio.h>
#include <math.h>
#include <climits>
#include <functional>
#include <string>
#include <cstring>
#include <set>
#define fi(n) scanf("%d",&n)
#define fo(n) printf("%d",n)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define all(v) v.begin(),v.end()
#define it(i,v) __typeof(v.begin()) i;
#define set(a,val) memset(a,val,sizeof(a))
#define rep(i,a,b) for(__typeof(a) i = (a); i < (b) ; i++)
#define rev(i,a,b) for(__typeof(a) i = (a); i >= (b) ; i--)

using namespace std;

int counts[2700];
bool arr[2700];



void markMultiples(int a, int n)
{
    int i = 2, num;
    while ( (num = i*a) <= n )
    {
        arr[ num]=1;
        counts[num]++;
        ++i;
    }
}
 
void SieveOfEratosthenes()
{	
	int n = 2700;
    for (int i=2; i<n; ++i)
    {
        if ( arr[i] == 0 )
        {
            markMultiples(i, n);
        }
    }
}


int main(){
	int t=0,n,i;
	set<int> myset;
	set<int>::iterator it;
	SieveOfEratosthenes();
	for(i=0;i<2700;i++)
		if(counts[i]>2) 
			myset.insert(i);
	fi(t);
	while(t--){
		fi(n);n--;
		it = myset.begin();
		while(n--)
			it++;
		cout<<(*it)<<endl;
	}
	return 0;
}