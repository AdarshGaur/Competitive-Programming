// Union-Find
// Time complexity - O(1) - amortized
//				   - O(logn) - worst

const int k = 1e5 +7;
template<int k> struct DSU{
	int parent[k], sizee[k];

	DSU(){
		for(int i=0; i<k; i++){
			parent[i]=i;
			sizee[i]=1;
		}
	}

	int find_set(int v){ // with path compression
		if(v==parent[v])
			return v;
		return parent[v] = find_set(parent[v]);
	}

	void union_set(int a, int b){
		a = find_set(a);
		b = find_set(b);
		if(a != b){
			if(sizee[a] < sizee[b]){
				swap(a,b);
			}
			parent[b] = a;
			sizee[a] += sizee[b];
		}
	}
};