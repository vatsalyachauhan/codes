#include <bits/stdc++.h>
using namespace std;
#define fi(n) scanf("%d",&n)
#define fo(n) printf("%d",n)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define all(v) v.begin(),v.end()
#define it(i,v) __typeof(v.begin()) i;
#define set(a,val) memset(a,val,sizeof(a))
#define rep(i,a,b) for(__typeof(a) i = (a); i < (b) ; i++)
#define rev(i,a,b) for(__typeof(a) i = (a); i >= (b) ; i--)

void make_subsets(int index,int size,int arr[],vector<int> &v){
	int sizes = 1<<size;
	int sum=0;
	rep(mask,0,sizes){
		sum = 0;
		rep(item,0,size)
			if(mask &(1<<item))
				sum += arr[index+item];
			v.pb(sum);
	}
	return;
}


int main () {
	int n,a,b;
	long long int ans=0;
	fi(n);fi(a);fi(b);
	vector<int> left,right;
	vector<int> ::iterator low,high;
	int arr[n];
	rep(i,0,n) fi(arr[i]);
	make_subsets(0,n/2,arr,left);
	make_subsets(n/2,n-n/2,arr,right);
	sort(right.begin(),right.end());
	
	int size = 1<<(n/2);
	
	rep(i,0,size){
		low = lower_bound(right.begin(),right.end(),a-left[i]);
		high = upper_bound(right.begin(),right.end(),b-left[i]);
		ans +=  (high-right.begin())-(low-right.begin());
	}
	cout<<ans<<endl;
  	return 0;
}