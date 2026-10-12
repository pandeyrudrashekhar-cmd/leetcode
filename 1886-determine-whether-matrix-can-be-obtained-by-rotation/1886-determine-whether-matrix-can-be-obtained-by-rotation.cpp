class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
         int n = mat.size();

        // Check all 4 possible orientations
        for (int rotation = 0; rotation < 4; rotation++) {
            
            // If current matrix matches target, return true
            if (mat == target) {
                return true;
            }

            // Step 1: Transpose the matrix
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    swap(mat[i][j], mat[j][i]);
                }
            }

            // Step 2: Reverse every row
            for (int i = 0; i < n; i++) {
                reverse(mat[i].begin(), mat[i].end());
            }
        }

        // No rotation matched the target
        return false;
    }
};