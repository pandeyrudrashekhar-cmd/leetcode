class Solution {
public:
void solve(int start, vector<int>& candidates, vector<int>& curr, int target, vector<vector<int>>& ans){
    if(target==0){
        ans.push_back(curr);
        return;
    }
    for(int i=start; i<candidates.size(); i++){
        //skip duplicates
        if(i>start && candidates[i]==candidates[i-1]) continue;
        //candidates are sorted so no pos can fit
        if(candidates[i]>target) break;
        curr.push_back(candidates[i]);

        solve(i+1, candidates,curr,target-candidates[i],ans);
        curr.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>curr;
        vector<vector<int>>ans;
        sort(candidates.begin(),candidates.end());
        solve(0,candidates,curr,target,ans);
        return ans;
    }
};