class Solution {
public:

    void solve(int index,
               int k,
               int target,
               vector<int>& ds,
               vector<vector<int>>& ans)
    {
        // Valid combination found
        if(target == 0 && ds.size() == k)
        {
            ans.push_back(ds);
            return;
        }

        // Pruning
        if(target < 0 || ds.size() > k)
            return;

        // Try every number from index to 9
        for(int i = index; i <= 9; i++)
        {
            // Choose
            ds.push_back(i);

            // Explore
            solve(i + 1,
                  k,
                  target - i,
                  ds,
                  ans);

            // Undo
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;
        vector<int> ds;

        solve(1, k, n, ds, ans);

        return ans;
    }
};