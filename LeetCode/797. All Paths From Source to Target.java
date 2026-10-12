class Solution {
    List<List<Integer>> allPaths = new ArrayList<>();
    int n;

    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        allPaths.clear();
        n = graph.length;
        backtrack(graph, new ArrayList<Integer>(List.of(0)), 0);
        return allPaths;
    }

    public void backtrack(int[][] graph, List<Integer> path, int curNode){
        if(curNode == n-1){
            allPaths.add(new ArrayList<>(path));
            return;
        }
        for(int v: graph[curNode]){
            path.add(v);
            backtrack(graph, path, v);
            path.remove(path.size() -1);
        }
        return;
    }
}
