class Solution {
    public int longestConsecutive(int[] nums) {
        int n = nums.length;
        int ans = 0;
        HashMap<Integer, Integer> map = new HashMap<>();
        DSU dsu = new DSU(n);
        for(int i=0; i<n; i++){
            if(map.containsKey(nums[i]))
                continue;
            map.put(nums[i], i);
            if(map.containsKey(nums[i]-1))
                dsu.union(i, map.get(nums[i]-1));
            if(map.containsKey(nums[i]+1))
                dsu.union(i, map.get(nums[i]+1));
            
            ans = Math.max(ans, dsu.rankOfSet(i));
        }
        return ans;
    }
}

public class DSU {
    private int[] parent;
    private int[] rank;         // height of tree rooted at i
    private int components;   // number of disjoint sets
    
    // Initialize - each element is it's own set
    // Time : O(n)
    public DSU(int n){
        parent = new int[n];
        rank = new int[n];
        components = n;
        for(int i=0; i<n; i++){
            parent[i] = i;      // each node is it's own parent (root)
            rank[i] = 1;        // all trees start with height 0
        }
    }
    
    // Find root of v's set - with PATH COMPRESSION
    // Time: amortized O(1)
    public int find(int v){
        if(v == parent[v])
            return v;
        return parent[v] = find(parent[v]);
    }
    
    // Union two sets - with UNION BY RANK
    // Returns treu if they were in different sets (a merge happened)
    // Time: Amortized O(1)
    public boolean union(int a, int b){
        int rootA = find(a);
        int rootB = find(b);        
        if(rootA == rootB)
            return false;       // already in the same set
        
        // Attach smaller tree under larger tree's root
        if(rank[rootA] < rank[rootB]){
            parent[rootA] = rootB;
            rank[rootB] += rank[rootA];
        }else {
            parent[rootB] = rootA;
            rank[rootA] += rank[rootB];
        }
        components--;
        return true;
    }
    
    // Number of disjoint sets remaining
    public int getComponents(){
        return components;
    }
    
    // Number of nodes in a disjoint set
    public int rankOfSet(int x){
        return rank[find(x)];
    }
    
    // Check if x and y are in the same set
    public boolean connected(int x, int y){
        return find(x) == find(y);
    }
}

