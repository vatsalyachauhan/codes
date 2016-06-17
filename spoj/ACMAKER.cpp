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
#define dg(n,s); printf("%s %d",s,n)
using namespace std;

//compile command== g++ -std=c++11 mycode.cpp

int main(){
	int n,useless;
	string word,line;
	fi(n);
	while(n){
		set<string> myset;
		rep(i,0,n+1){
			getline(cin,line);
			iss myline(line);
			while(myline>>word)myset.insert(word); 
		}
		while(1){
			string source,target;
			getline(cin,line);
			iss myline(line);
			myline>>word;
			target = word;
			while(myline>>word){
				if(myset.find(word)==myset.end()){
					source += word;
				}
			}
			if(target == "LAST" && source == "CASE")
				break;
			else{
				vector<int> pos[26];
				int tlen = target.size();
				rep(i,0,tlen) pos[target[i]-'A'].pb(i);
				int ans[tlen];
				memset(ans,0,sizeof(ans));
				rep(i,0,source.size()){
					if(pos[source[i]-'a'].size()){
						vector<int>::reverse_iterator  ritr= pos[source[i]-'a'].rbegin();
						while(ritr!=pos[source[i]-'a'].rend()){
							useless = *ritr;
							ans[useless] = ans[useless] + ((useless>=1)?ans[useless-1]:1);
							ritr++;
							
							rep(j,0,tlen) cout<<ans[j]<<" ";
							pn;
						}
					}
				}
				cout<<target<<" ";
				if(ans[tlen-1]){
					cout<<"can be formed in "<<ans[tlen-1]<<" ways"<<endl;
				}
				else{
					cout<<"is not a valid abbreviation"<<endl;
				}
			}
		}
		fi(n);
	}
	return 0;
}
