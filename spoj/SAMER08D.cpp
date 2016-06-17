#include <bits/stdc++.h>
#define fi(n) scanf("%d",&n)
#define fo(n) printf("%d",n)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define all(v) v.begin(),v.end()
#define it(i,v) __typeof(v.begin()) i;
#define set(a,val) memset(a,val,sizeof(a))
#define rep(i,a,b) for(__typeof(a) i = (a); i < (b) ; i++)
#define rev(i,a,b) for(__typeof(a) i = (a); i >= (b) ; i--)
#define tr(vec,it) for(__typeof(vec.begin()) it = vec.begin();it!=vec.end();++it)
#define lli long long int
#define vi vector<int>
#define pii pair< int ,int >
#define iss istringstream
#define oss ostringstream
#define sqr(x) (x)*(x)
#define ESP (1e-9)
#define PI 3.1415926535897932384626433832795
#define ps printf(" ")
#define pn printf("\n")
using namespace std;

//compile command== g++ -std=c++11 mycode.cpp
int arr[1010][1010];
bool avl[1010][1010];
int siz[1010][1010];

int main(){
	int k,rows,cols;
	fi(k);
	while(k){
		string str1,str2;
		cin>>str1>>str2;
		rows = str1.size();
		cols = str2.size();
		if(rows < k || cols < k){
			cout<<0<<endl;
		}
		else{
			rows++;
			cols++;
			memset(arr,0,sizeof(arr));
			memset(siz,0,sizeof(siz));
			rep(i,1,rows){
				rep(j,1,cols){
					arr[i][j]=max( arr[i-1][j], arr[i][j-1] );
					if(str1[i-1]==str2[j-1]){
						siz[i][j] = siz[i-1][j-1] + 1;
						int z=siz[i][j];
						if(z>=k){
							rep(var,k,z+1) arr[i][j] = max(arr[i][j],arr[i-var][j-var] + var);
						}
					}
				}
			}
			cout<<arr[rows-1][cols-1]<<endl;
		}
		fi(k);
	}
	return 0;
}
