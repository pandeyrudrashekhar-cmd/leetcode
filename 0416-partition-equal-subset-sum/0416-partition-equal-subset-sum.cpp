class Solution {
public:

    bool canPartition(vector<int>& nums)
    {
        int n = nums.size();

        int sum = 0;

        for(int x : nums)
            sum += x;

        // Odd sum cannot be partitioned equally
        if(sum % 2 != 0)
            return false;

        int target = sum / 2;

        // dp[i][t] = Can we make sum t
        // using elements from 0 to i?
        vector<vector<bool>> dp(n,
                vector<bool>(target+1,false));

        // Sum 0 is always possible
        for(int i=0;i<n;i++)
            dp[i][0]=true;

        // Using first element
        if(nums[0] <= target)
            dp[0][nums[0]] = true;

        // Fill DP table
        for(int i=1;i<n;i++)
        {
            for(int t=1;t<=target;t++)
            {
                // Don't take
                bool notTake = dp[i-1][t];

                bool take = false;

                // Take current element
                if(nums[i] <= t)
                    take = dp[i-1][t-nums[i]];

                dp[i][t] = take || notTake;
            }
        }

        return dp[n-1][target];
    }
};