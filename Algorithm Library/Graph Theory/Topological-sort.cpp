// Topological Sort through DFS
// Time Complexity - O(V+E)

#include<bits/stdc++.h>
using namespace std;

#define endl "\n"

int n; // number of vertices
vector<vector<int>> G;
vector<int> visited;
vector<int> ans;

// returns false if cycle present in the graph
bool dfs(int v){
    if(visited[v] == 1) return false;
    if(visited[v] == 2) return true;
    visited[v] = 1;
    for (int u : G[v]){
        if (!visited[u]){
            if(!dfs(u))
                return false;
        }
    }
    visited[v] = 2;
    ans.push_back(v);
    return true;
}

bool topologicalSort(){
    visited.resize(n, 0);
    ans.clear();
    for (int i=0; i<n; ++i){
        if (!visited[i]){
            if(!dfs(i))
                return false;
        }
    }
    return true;
}

int main(){
	int edges;
    cin >> n >> edges;
    G = vector<vector<int>>(n);
    for(int i=0; i<edges; i++){
        int u, v;
        cin >> u >> v;
        u--, v--; // no need if 0-based indexing
        // edge u to v means u is dependent on v
        // swap them in opposite case
        G[u].push_back(v);
    }

    if(!topologicalSort()){
        cout << "Topological Sort Not Possible. DAG has a cycle." << endl;
    }else{
        cout << "Topological Order is :- " << endl;
        for(int &i: ans)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
