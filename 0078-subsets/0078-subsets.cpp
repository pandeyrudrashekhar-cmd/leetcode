class Solution {
public:
void solve(int idx, vector<int>& arr, vector<int>& curr,vector<vector<int>>& ans){
    if(idx==arr.size()){
        ans.push_back(curr);
        return;
    }
    //choice 1:- take the curr element
    curr.push_back(arr[idx]);
    solve(idx+1, arr, curr,ans);

    //undo the choice
    curr.pop_back();
    //choice2:- skip the curr option
    solve(idx+1,arr,curr,ans);
}
    vector<vector<int>> subsets(vector<int>& arr) {
        vector<int>curr;
        vector<vector<int>>ans;
       solve(0,arr,curr,ans);
       return ans;
        
    }
};