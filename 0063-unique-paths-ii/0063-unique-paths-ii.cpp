class Solution {
public:

    int solve(int i, int j, vector<vector<int>>& grid,
              vector<vector<int>>& dp)
    {
        // Out of boundary
        if(i < 0 || j < 0)
            return 0;

        // Obstacle cell
        if(grid[i][j] == 1)
            return 0;

        // Reached starting cell
        if(i == 0 && j == 0)
            return 1;

        // Already calculated
        if(dp[i][j] != -1)
            return dp[i][j];

        // Ways from top + left
        return dp[i][j] = solve(i-1, j, grid, dp)
                         + solve(i, j-1, grid, dp);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(m-1, n-1, grid, dp);
    }
};