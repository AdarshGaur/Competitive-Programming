class Solution {
    public boolean canFinish(int numCourses, int[][] preRequisites) {
        List<List<Integer>> graph = new ArrayList<>();
        for(int i=0; i<numCourses; i++){
            graph.add(new ArrayList<>());
        }
        int edgeCount = preRequisites.length;
        for(int i=0; i<edgeCount; i++){
            int u = preRequisites[i][0];
            int v = preRequisites[i][1];
            graph.get(u).add(v);
        }

        int[] visited = new int[numCourses];
        for(int i=0; i<numCourses; i++){
            if(visited[i] == 0){
                boolean canFinish = findCyclicDependency(graph, visited, i);
                if(canFinish == false)
                    return false;
            }
        }
        return true;
    }

    private boolean findCyclicDependency(List<List<Integer>> graph, int[] visited, int curNode){
        if(visited[curNode] == 2)
            return true;
        if(visited[curNode] == 1)
            return false;
        
        visited[curNode] = 1;
        for(int v: graph.get(curNode)){
            boolean canFinish = findCyclicDependency(graph, visited, v);
            if(canFinish == false)
                return false;
        }
        visited[curNode] = 2;
        return true;
    }
}
