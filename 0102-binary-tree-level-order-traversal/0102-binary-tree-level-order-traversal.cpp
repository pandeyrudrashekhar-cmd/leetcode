
class Solution {
public:
int levels(TreeNode* root){
    if(root==NULL) return 0;
    return 1+max(levels(root->left),levels(root->right));
}
void nthlevel(TreeNode* root, int currlevel, int level, vector<int>&v){
    if(root==NULL) return;
    if(currlevel==level){
     v.push_back(root->val);
    return;
    } 
    nthlevel(root->left, currlevel+1, level,v);
    nthlevel(root->right, currlevel+1, level,v);

}
void lorder(TreeNode* root,vector<vector<int>>& ans){
    int n=levels(root);
    for(int i=1; i<=n; i++){
        vector<int>v;
        nthlevel(root,1,i,v);
        ans.push_back(v);
        cout<<endl;
    }
}
    vector<vector<int>> levelOrder(TreeNode* root) {
       vector<vector<int>>ans;
        lorder(root,ans);
        return ans;
    }
};