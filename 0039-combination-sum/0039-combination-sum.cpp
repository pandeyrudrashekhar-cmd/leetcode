class Solution {
public:

void solve(vector<vector<int>>&ans,vector<int>& candidates, vector<int>& curr, int target, int idx){
    if(target==0){
        ans.push_back(curr);
        return;
    }
    if(target<0) return;
    for(int i=idx; i<candidates.size(); i++){
        curr.push_back(candidates[i]);
        solve(ans,candidates,curr,target-candidates[i],i);
        curr.pop_back();
    }
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>curr;
        solve(ans,candidates,curr,target,0);
        return ans;
    }
};