class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int bestRow = 0;
        int maxOnes = 0;

        for (int i = 0; i < mat.size(); i++) {
            int count = 0;
            for (int val : mat[i]) {
                if (val == 1) {
                    count++;
                }
            }
            // Using strictly greater (>) ensures we keep the smallest row index on ties
            if (count > maxOnes) {
                maxOnes = count;
                bestRow = i;
            }
        }

        return {bestRow, maxOnes};
    }
};