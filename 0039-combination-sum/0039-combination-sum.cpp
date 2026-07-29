class Solution {
public:

    void solve(int index,
               int target,
               vector<int>& candidates,
               vector<int>& ds,
               vector<vector<int>>& ans)
    {
        // Base Case: Target achieved
        if(target == 0)
        {
            ans.push_back(ds);
            return;
        }

        // Base Case: No more elements
        if(index == candidates.size())
            return;

        // -----------------------------
        // Choice 1 : Take current element
        // -----------------------------
        if(candidates[index] <= target)
        {
            // Choose
            ds.push_back(candidates[index]);

            // Explore
            // Stay on same index because reuse is allowed
            solve(index,
                  target - candidates[index],
                  candidates,
                  ds,
                  ans);

            // Undo (Backtrack)
            ds.pop_back();
        }

        // -----------------------------
        // Choice 2 : Skip current element
        // -----------------------------
        solve(index + 1,
              target,
              candidates,
              ds,
              ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> ds;

        solve(0, target, candidates, ds, ans);

        return ans;
    }
};