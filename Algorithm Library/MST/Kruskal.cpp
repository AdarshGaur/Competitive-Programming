// Kruskal's MST algorithm
// with DSU
// Time complexity - O(MlogN)


int n, m;      // no. of nodes and edges

vector<pair<int, pair<int,int>>> edge; // {weight, {from,to}}

vector<int> parent;
vector<int> size;

bool comp(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b){
	// if(a.first==b.first){
	// 	return a.second.first < b.second.first;
	// }
	return a.first <= b.first ;
}

void init(){
	// mst.clear();
	parent.resize(n);
	size.resize(n);
	for(int i=0, i<n; i++){
		parent[i]=i;
		size[i]=1;
	}
	sort(edges.begin(), edges.end(), comp);
}


void make_set(int v){
	parent[v] = v;
	size[v] = 1;
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
		if(size[a] < size[b]){
			swap(a,b);
		}
		parent[b] = a;
		size[a] += size[b];
	}
}


// auto mst = edge;   // for storing the MST

int kruskal(){        // return total cost of MST
	int mincost=0;
	int edg =0;
	// sort(edges)
	for(auto e : edge){
		int from = e.second.first;
		int to = e.second.second;
		int w = e.first;
		if(find_set(from)!=find_set(to)){
			mincost += w;
			edg++;
			// mst.push_back(e);
			union_set(from , to);
			if(edg == (n-1)){
				break;
			}
		}
	}
	return mincost;
}
