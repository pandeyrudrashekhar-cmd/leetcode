class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
       int n=matrix.size();
       vector<vector<int>>dp(n,vector<int>(n,0));
       //base case:- first row same rhega
       for(int j=0; j<n; j++){
        dp[0][j]=matrix[0][j];
       } 
       //fill dp tble
       for(int i=1; i<n; i++){
        for(int j=0; j<n; j++){
            int up=dp[i-1][j];
            int leftdiagonal=INT_MAX;
            if(j>0) leftdiagonal=dp[i-1][j-1];
            int rightdiagonal=INT_MAX;
            if(j<n-1) rightdiagonal=dp[i-1][j+1];
            dp[i][j]=matrix[i][j]+min(up,min(leftdiagonal,rightdiagonal));
        }
       }
       int ans=INT_MAX;
       for(int j=0; j<n; j++){
        ans=min(ans,dp[n-1][j]);
       }
       return ans;
    }
};