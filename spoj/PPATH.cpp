#include <iostream>
#include <cstdio>
#include <math.h>
#include <vector>
#include <queue>
#define fi(n) scanf("%d",&n)
using namespace std;

bool bipartite(vector<vector<int> > g, int i, int n, bool *visited, int* color){
	vector<int> :: iterator it;
	int temp;
	queue<int> q;

	visited[i]=true; color[i]=0;
	q.push(i);
	while(!q.empty()){
		temp = q.front();
		q.pop();
		for(it=g[temp].begin(); it!=g[temp].end(); it++){
			if(!visited[*it]){
				visited[*it]=true;
				color[*it] = 1-color[temp];
				q.push(*it);
			}
			else{
				if(color[*it]==color[temp])
					return false;
			}
		}
	}
	return true;
}


int main(){
	int T,n,e,i,u,v,j;
	fi(T);
	bool answer;
	for(j=1;j<=T;j++){

		fi(n);fi(e);
		bool visited[n];
		int color[n];
		int i;
		for(i=0;i<n;i++) visited[i]=false, color[i]=-1;
		answer=true;

		
		vector<vector<int> > g(n);
		for(i=0;i<e;i++){
			fi(u);fi(v); u--; v--;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		printf("Scenario #%d:\n",j);
		for(i=0;i<n;i++){
			if(!visited[i])
				answer = answer &&  bipartite(g,i,n,visited,color);
			if(!answer)
				break;
		}
		if(answer)
			printf("No suspicious bugs found!\n");
		else
			printf("Suspicious bugs found!\n");
	}
	return 0;
}

https://www.wiknix.com/no-internet-access-in-windows-8-1/