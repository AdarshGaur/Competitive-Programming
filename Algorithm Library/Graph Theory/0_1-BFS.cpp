// Standard 0-1 BFS

// int means int64_t
const int INF = 1e18;

int x=1; // x can be any positive number
const int N = 1e6 +7;
vector<int> dis(N, INF);
vector<bool> vis(N, false);
deque<int> q;

void bfs0x(int s){
	dis[s]=0;
	vis[s]=true;
	q.push_back(s);
	while(!q.empty()){
		int cur = q.front();
		q.pop_front();
		if(vis[cur])continue;
		vis[cur]=true;
		for(auto e : adj[cur]){ // adj[cur] - [{vertex, weight}]
			auto u = e.first;
			auto w = e.second;
			if(d[cur] + w < d[u]){
				dis[u] = dis[cur] + w;
				if(w==0){
					q.push_front(u);
				}else{
					q.push_back(u);
				}
			}
		}
	}
}

