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

using namespace std;

int time_table[50][50];
int toll_table[50][50];
bool visited[50];
int minimum_cost;
int time_for_minimum;
int n,times;

void dfs(int city, int cost,int delay){
	visited[city] = true;
	if(city==n-1 && minimum_cost > cost && delay <= times){
		minimum_cost = cost;
		time_for_minimum = delay;
	} 
	rep(i,0,n){
		if(!visited[i] && minimum_cost > cost && delay <= times){
			dfs(i,cost+toll_table[city][i],delay+time_table[city][i]);
		}
	}
	visited[city] = false;
	return;
}


int main(){
	int cost,delay;
	fi(n);fi(times);
	while(1){
		if(n==0 && times==0) break;
		cost = 0; delay = 0;
		minimum_cost = INT_MAX;
		set(visited,false);
		rep(i,0,n)rep(j,0,n) fi(time_table[i][j]);
		rep(i,0,n)rep(j,0,n) fi(toll_table[i][j]);
		dfs(0,cost,delay);
		printf("%d %d\n",minimum_cost,time_for_minimum);
		fi(n);fi(times);
	}
	
	return 0;
}