class Solution {
public:

    void solve(int index,
               vector<int>& nums,
               vector<int>& ds,
               vector<vector<int>>& ans)
    {
        // Store the current subset
        ans.push_back(ds);

        // Try every element starting from index
        for(int i = index; i < nums.size(); i++)
        {
            // Skip duplicates at the same level
            if(i > index && nums[i] == nums[i - 1])
                continue;

            // Choose
            ds.push_back(nums[i]);

            // Explore
            solve(i + 1, nums, ds, ans);

            // Undo
            ds.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> ds;

        solve(0, nums, ds, ans);

        return ans;
    }
};