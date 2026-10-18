class Solution {
public:
    void bfs(int start, vector<vector<int>>& adj, vector<bool>& vis) {

        queue<int> q;
        q.push(start);
        vis[start] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            // Check all cities connected to the current city
            for (int j = 0; j < adj.size(); j++) {
                if (adj[node][j] == 1 && !vis[j]) {
                    vis[j] = true;
                    q.push(j);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<bool> vis(n, false);
        int count = 0;

        // Find every separate connected component
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                bfs(i, isConnected, vis);
                count++;
            }
        }

        return count;
    }
};