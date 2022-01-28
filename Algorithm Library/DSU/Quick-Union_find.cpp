// Union-Find
// Time complexity - O(1) - amortized
//				   - O(logn) - worst

struct DSU{
	vector<int> par, weight;
	int components, nodes;

	DSU(int n){
		nodes = n;
		components = n;
		par.resize(n+1);
		weight.resize(n+1, 1);
		iota(par.begin(), par.end(), 0);
	}

	int Find(int v){ // find set with path compression
		if(v==par[v])
			return v;
		return par[v] = Find(par[v]);
	}

	bool Union(int a, int b){
		a = Find(a), b = Find(b);
		if(a == b) return false;
		if(weight[a] > weight[b]){
			swap(a,b);
		}
		par[a] = b;
		weight[b] += weight[a];
		components -= 1;
		return true;
	}

	int CntofComponent(){ // return the total number of components
		return components;
	}

	int NodeinComponent(int x){ // return the number of nodes in component x;
		return weight[Find(x)];
	}
};