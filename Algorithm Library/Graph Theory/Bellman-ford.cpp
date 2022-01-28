// Bellman-Ford's Algorithm
// single source shortest path with negative edge weight
// time complexity - O(nm)

const int INF = 1e17;

vector<pair<pair<int,int> , int> > edge; // {{from,to}, cost}
vector<int> dis; // distances
vector<int> par; // parents

int n, m; // n --> nodes , m --> edges

int bellmanford(int source){
	dis.assign(n, INF);
	par.assign(n, -1);
	dis[source]=0;

	for(int i=1; i<=n; ++i){
		// traverse all the edges n times and do relations from every edge.
		// if relaxation happens on the nth time too then negative cycle is present.

		bool any = false;
		for(int j=0; j<m; ++j){
			int from = edge[j].first.first;
			int to = edge[j].first.second;
			int cost = edge[j].second;
			if(dis[to]>dis[from]+cost){

				if(i==n){ // negative cycle found
					return -1;
				}
				dis[to] = max(-INF, dis[from]+cost);
				par[to] = from;
				any=true;
			}
		}
		if(!any){
			return 1;
		}
	}

	return 1;
}