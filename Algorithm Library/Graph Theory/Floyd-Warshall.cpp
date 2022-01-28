
// Floyd-Warshall's Algorithm
// All source sortest path algorithm
// time complexity - O(n^3)

#define INF 1e18
int n;			// no. of nodes
int d[n][n];	// distances between all nodes 

void floydWarshall(){
	// assigning initial values as INF or 0
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			d[i][j] = (i==j ? 0 : INF);
		}
	}
	for(int k=0; k<n; ++k){
		for(int i=0; i<n; ++i){
			for(int j=0; j<n; ++j){
				if (d[i][k] < INF && d[k][j] < INF){ // condition to ignore the not connected components.
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}
	}
}