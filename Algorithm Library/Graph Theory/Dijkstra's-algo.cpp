
// Dijkstra's Algorithm
// single source shortest path without negative edges
// Time Complexity - O(n^2)

const int INF = 1e18;
const int N = 2e5 +7;
vector<pair<int, int>> adj[N]; // edges : { vertex, weight }
int dist[N]; // to store the distance
int par[N]; // to restore the path or parents
bool vis[N];
int n;

void init(){
    for(int i=0; i<n; i++){
        adj[i].clear();
        dist[i]=INF;
        par[i]=-1;
        vis[i]=false;
    }
}

void dijkstra(int s){
    //cin>>n;
    dist[s] = 0;
    set<pair<int,int>> q;
    q.insert({0,s});
    while(!q.empty()){
        int from = q.begin()->second;
        q.erase(q.begin());
        if(vis[from])continue;
        vis[from] = true; // mark the vertex
        for (auto edge : adj[from]) {
            int to = edge.first; // vertex
            int w = edge.second; //weight
            if (dist[from] + w < dist[to]){
                dist[to] = dist[from] + w;
                par[to] = from;
                q.insert({dist[to], to}); // a single vertex can have multiple insertions, so mark them visited after only after popping out of the set;
            }
        }
    }
}


int32_t main(){
    //fastio;
    init();
    // input the edges;
    dijkstra(s);
}