#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector<vector<int> > g(10010);
bool visited[10010];
int global;

int dfs(int v) {
	visited[v] = true;
	int max1 = 0,max2=0,local_path;
	vector<int>::iterator it = g[v].begin();

	for(; it != g[v].end(); it++) {
		if(!visited[*it]) {
			int x = dfs(*it);
			if(x>max2 && x <=max1)
				max2 = x;
			else if(x > max1){
				max2 = max1; max1 = x;
			}
		}
	}
	local_path = max1 + max2;
	if(local_path>global)
		global = local_path;
	return max1+1;
}

int main() {
    int n,i;
   	cin >> n;
    int u, v;
    for(i=1;i<n;i++){
    	cin >> u >> v;
    	u--; v--;
    	g[u].push_back(v);
    	g[v].push_back(u);
	}
    dfs(0);
    cout << global << endl;
	return 0;
}
