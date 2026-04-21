class Solution {
    // DSU
    public class DSU {
        private int[] parent;
        private int[] rank;
        private int components;

        public DSU(int n){
            parent = new int[n];
            rank = new int[n];
            components = n;

            for(int i=0; i<n; i++){
                parent[i] = i;
                rank[i] = 1;
            }
        }

        public int find(int v){
            if(v == parent[v])
                return v;
            return parent[v] = find(parent[v]);
        }

        public boolean union(int a, int b){
            int rootA = find(a);
            int rootB = find(b);

            if(rootA == rootB)
                return false;
            
            if(rank[rootA] < rank[rootB]){
                parent[rootA] = rootB;
                rank[rootB] += rank[rootA];
            }else{
                parent[rootB] = rootA;
                rank[rootA] += rank[rootB];
            }
            components--;
            return true;
        }

        public boolean connected(int x, int y){
            return find(x) == find(y);
        }
    }

    public int minimumHammingDistance(int[] source, int[] target, int[][] allowedSwaps) {
        int n = source.length;

        // create the DSUs for all source indexes
        DSU dsu = new DSU(n);
        for(int[] pair: allowedSwaps){
            dsu.union(pair[0], pair[1]);
        }

        // keep a hashtable for parent(i) having all values and their occurences
        HashMap<Integer, HashMap<Integer, Integer>> idxToValueMap = new HashMap<>();
        for(int i=0; i<n; i++){
            int par = dsu.find(i);
            idxToValueMap.putIfAbsent(par, new HashMap<>());
            HashMap<Integer, Integer> freq = idxToValueMap.get(par);
            freq.put(source[i], freq.getOrDefault(source[i], 0) +1);
        }

        int hammingDistance = n;
        for(int i=0; i<n; i++){
            int par = dsu.find(i);
            HashMap<Integer, Integer> map = idxToValueMap.get(par);
            if(map.getOrDefault(target[i], 0) > 0){
                hammingDistance--;
                map.put(target[i], map.get(target[i]) -1);
            }
        }
        return hammingDistance;
    }
}
