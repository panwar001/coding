class Solution {
    // graph
    // dfs

    int count = 0;

    void dfs(vector<vector<char>>& grid, int i, int j) {

        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {
            return;
        }
        
        if (grid[i][j] == '0') {
            return;
        }
        // set the visited nodes as zero
        if (grid[i][j] == '1') {
            grid[i][j] = '0';
        }


        // check the valid position to move
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i , j + 1);
        dfs(grid, i , j - 1);
    }

public:
    int numIslands(vector<vector<char>>& grid) {

        // dfs
        int rows = grid.size();
        int columns = grid[0].size();

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {

                if (grid[i][j] == '1') {
                    count++;
                }
                dfs(grid, i, j);
                
            }
        }
        return count;
    }
};
