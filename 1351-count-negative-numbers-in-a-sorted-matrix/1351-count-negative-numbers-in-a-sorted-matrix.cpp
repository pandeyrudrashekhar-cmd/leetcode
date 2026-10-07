class Solution {
public:
    int countNegatives(vector<vector<int>>& mat) {
        int count=0;
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat[0].size(); j++){
                if(mat[i][j]<0) count++;
            }
        }
        return count;
    }
};