class Solution {
public:

    void solve(int index,
               int target,
               vector<int>& candidates,
               vector<int>& ds,
               vector<vector<int>>& ans)
    {
        // Target achieved
        if(target == 0)
        {
            ans.push_back(ds);
            return;
        }

        // Try every candidate starting from current index
        for(int i = index; i < candidates.size(); i++)
        {
            // Skip duplicates at the same recursion level
            if(i > index && candidates[i] == candidates[i - 1])
                continue;

            // Since array is sorted, no need to continue
            if(candidates[i] > target)
                break;

            // Choose
            ds.push_back(candidates[i]);

            // Explore (move to next index because reuse is NOT allowed)
            solve(i + 1,
                  target - candidates[i],
                  candidates,
                  ds,
                  ans);

            // Undo
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> ds;

        solve(0, target, candidates, ds, ans);

        return ans;
    }
};