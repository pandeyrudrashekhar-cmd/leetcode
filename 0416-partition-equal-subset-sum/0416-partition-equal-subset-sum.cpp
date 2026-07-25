class Solution {
public:

    bool solve(int index, int target,
               vector<int>& nums,
               vector<vector<int>>& dp)
    {
        // Target achieved
        if(target == 0)
            return true;

        // Only first element left
        if(index == 0)
            return nums[0] == target;

        // Already calculated
        if(dp[index][target] != -1)
            return dp[index][target];

        // Don't take current element
        bool notTake = solve(index-1, target, nums, dp);

        bool take = false;

        // Take current element
        if(nums[index] <= target)
            take = solve(index-1,
                         target-nums[index],
                         nums,
                         dp);

        return dp[index][target] = take || notTake;
    }

    bool canPartition(vector<int>& nums)
    {
        int n = nums.size();

        int sum = 0;

        for(int x : nums)
            sum += x;

        // Odd sum can never be divided equally
        if(sum % 2 != 0)
            return false;

        int target = sum / 2;

        vector<vector<int>> dp(n,
                vector<int>(target+1,-1));

        return solve(n-1,target,nums,dp);
    }
};