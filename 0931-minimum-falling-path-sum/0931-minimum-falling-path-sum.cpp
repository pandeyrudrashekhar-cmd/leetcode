class Solution {
public:

    int solve(int i, int j, vector<vector<int>>& matrix,
              vector<vector<int>>& dp,
              vector<vector<bool>>& vis) {

        int n = matrix.size();

        // Out of bounds
        if (j < 0 || j >= n)
            return INT_MAX;

        // Base case
        if (i == 0)
            return matrix[0][j];

        // Already computed
        if (vis[i][j])
            return dp[i][j];

        vis[i][j] = true;

        int up = solve(i - 1, j, matrix, dp, vis);
        int leftDiagonal = solve(i - 1, j - 1, matrix, dp, vis);
        int rightDiagonal = solve(i - 1, j + 1, matrix, dp, vis);

        dp[i][j] = matrix[i][j] + min({up, leftDiagonal, rightDiagonal});

        return dp[i][j];
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {

        int n = matrix.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<vector<bool>> vis(n, vector<bool>(n, false));

        int ans = INT_MAX;

        // Try ending at every column of the last row
        for (int j = 0; j < n; j++) {
            ans = min(ans, solve(n - 1, j, matrix, dp, vis));
        }

        return ans;
    }
};