class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty())
            return 0;

        int count = 0;
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {

                // When we find a '1', we've found a new island
                if (grid[i][j] == '1') {
                    count++;

                    queue<pair<int, int>> q;
                    q.push({i, j});
                    grid[i][j] = '0'; // Sink the starting land

                    // BFS to sink the rest of the connected island
                    while (!q.empty()) {
                        int r = q.front().first;
                        int c = q.front().second;
                        q.pop();

                        // Check Up
                        if (r - 1 >= 0 && grid[r - 1][c] == '1') {
                            q.push({r - 1, c});
                            grid[r - 1][c] = '0';
                        }
                        // Check Down
                        if (r + 1 < m && grid[r + 1][c] == '1') {
                            q.push({r + 1, c});
                            grid[r + 1][c] = '0';
                        }
                        // Check Left
                        if (c - 1 >= 0 && grid[r][c - 1] == '1') {
                            q.push({r, c - 1});
                            grid[r][c - 1] = '0';
                        }
                        // Check Right
                        if (c + 1 < n && grid[r][c + 1] == '1') {
                            q.push({r, c + 1});
                            grid[r][c + 1] = '0';
                        }
                    }
                }
            }
        }

        return count;
    }
};