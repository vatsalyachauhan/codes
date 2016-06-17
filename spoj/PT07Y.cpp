#include <iostream>
#include <cstdio>
#include <vector>
#define fi(n) scanf("%d",&n)
#define lli long long int
using namespace std;

vector<vector<int> > g(10010);
bool visited[10010];

bool dfs(int v,int parent) {
	visited[v] = true;
	bool temp = false;
	vector<int>::iterator it = g[v].begin();
	for(; it != g[v].end(); it++) {
		if(visited[*it] && (*it) != parent)
			return true;
		temp = temp || dfs(*it, v);
	}
	return temp;
}

bool allvisited(int n){
	int i;
	for(i=0;i<n;i++){
		if(!visited[i])
			return false;
	}
	return true;
}

int main(){
	int n,m,i,u,v;
	fi(n);fi(m);
	for(i=0;i<m;i++){
		fi(u);fi(v); u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	if(n-1==m){
		if(dfs(0,-1) || !allvisited(n))
			printf("NO\n");
		else
			printf("YES\n");
	}
	else{
		printf("NO\n");
	}
	return 0;
}
