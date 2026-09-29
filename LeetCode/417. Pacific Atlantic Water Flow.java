class Solution {
    private int n, m;
    private int[] directions = {0, 1, 0, -1, 0};

    public List<List<Integer>> pacificAtlantic(int[][] heights) {
        n = heights.length;
        m = heights[0].length;
        boolean[][] canDrainToPacific = new boolean[n][m];
        boolean[][] canDrainToAtlantic = new boolean[n][m];

        for(int i=0; i<n; i++){
            // pacific ocean
            dfs(heights, canDrainToPacific, i, 0);

            // atlantic ocean
            dfs(heights, canDrainToAtlantic, i, m-1);
        }
        for(int j=0; j<m; j++){
            // pacific ocean
            dfs(heights, canDrainToPacific, 0, j);

            // atlantic ocean
            dfs(heights, canDrainToAtlantic, n-1, j);
        }


        List<List<Integer>> result = new ArrayList<>();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(canDrainToPacific[i][j] && canDrainToAtlantic[i][j]){
                    result.add(Arrays.asList(i, j));
                }
            }
        }
        return result;
    }

    private void dfs(int[][] heights, boolean[][] visited, int r, int c){
        if(visited[r][c]) return;
        visited[r][c] = true;
        for(int i=0; i<4; i++){
            int x = r + directions[i];
            int y = c + directions[i+1];

            if(x < 0 || y < 0 || x >= n || y >= m) continue;
            if(visited[x][y]) continue;
            if(heights[x][y] < heights[r][c]) continue;
            dfs(heights, visited, x, y);
        }
        return;
    }
}

