class Solution {
    private int n, m;
    private int[] directions = {0, 1, 0, -1, 0};

    public int numIslands(char[][] grid) {
        n = grid.length;
        m = grid[0].length;
        boolean[][] visited = new boolean[n][m];

        int islands = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    islands++;
                    visited[i][j] = true;
                    dfs(grid, visited, i, j);
                }
            }
        }
        return islands;
    }

    private void dfs(char[][] grid, boolean[][] visited, int r, int c){
        for(int i=0; i<4; i++){
            int x = r + directions[i];
            int y = c + directions[i+1];

            if(x < 0 || y < 0 || x == n || y == m) continue;
            if(grid[x][y] == '0' || visited[x][y]) continue;
            visited[x][y] = true;
            dfs(grid, visited, x, y);
        }
        return;
    }
}

