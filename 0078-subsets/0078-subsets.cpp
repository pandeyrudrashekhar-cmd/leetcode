class Solution {
public:

    void solve(int index,
               vector<int>& arr,
               vector<int>& ds,
               vector<vector<int>>& ans)
    {
        // Base Case
        if(index == arr.size())
        {
            ans.push_back(ds);
            return;
        }

       
        // Choice 1 : Take current element
        
        ds.push_back(arr[index]);

        solve(index + 1, arr, ds, ans);

        // Undo the choice (Backtracking)
        ds.pop_back();

       
        // Choice 2 : Don't take
       
        solve(index + 1, arr, ds, ans);
    }

    vector<vector<int>> subsets(vector<int>& arr)
    {
        vector<vector<int>> ans;
        vector<int> ds;

        solve(0, arr, ds, ans);

        return ans;
    }
};