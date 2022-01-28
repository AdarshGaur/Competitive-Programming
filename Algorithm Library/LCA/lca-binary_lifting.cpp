
// LCA with Binary Lifting
// Time complexity - O(NlogN) - for preprocessing
//                 - O(logN) - per query

int n, lmax; 
vector<vector<int>> adj;

// tin and tout to check if u is an ancestor of v in O(1) time
int timer;
vector<int> tin, tout;
vector<vector<int>> up;

void dfs(int v, int p){
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i<=lmax; ++i){
        up[v][i] = up[up[v][i-1]][i-1];
    }
    for (int u : adj[v]){
        if (u != p){
            dfs(u, v);
        }
    }
    tout[v] = ++timer;
}


// here we use those tin and tout to check if u is an ancestor of v or not !
bool is_ancestor(int u, int v){
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v){
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = lmax; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v)){
            u = up[u][i];
        }
    }
    return up[u][0];
}


void preprocess(int root){
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    lmax = ceil(log2(n));
    up.assign(n, vector<int>(lmax + 1));
    dfs(root, root);
}