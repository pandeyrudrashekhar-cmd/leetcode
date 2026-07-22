class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        // If starting cell is blocked
        if(grid[0][0] == 1)
            return 0;

        // dp[i][j] stores number of ways to reach (i,j)
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Starting cell
        dp[0][0] = 1;

        // Fill DP table
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                // Skip starting cell
                if(i == 0 && j == 0)
                    continue;

                // Obstacle cell
                if(grid[i][j] == 1)
                {
                    dp[i][j] = 0;
                }
                else
                {
                    // Ways from top
                    if(i > 0)
                        dp[i][j] += dp[i-1][j];

                    // Ways from left
                    if(j > 0)
                        dp[i][j] += dp[i][j-1];
                }
            }
        }

        // Answer
        return dp[m-1][n-1];
    }
};