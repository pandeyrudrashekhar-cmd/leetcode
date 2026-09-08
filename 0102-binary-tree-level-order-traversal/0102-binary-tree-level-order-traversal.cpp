class Solution {
public:

    // Returns number of levels in the tree
    int levels(TreeNode* root) {

        if (root == NULL)
            return 0;

        return 1 + max(
            levels(root->left),
            levels(root->right)
        );
    }

    // Collect all nodes present at a particular level
    void nthlevel(
        TreeNode* root,
        int currLevel,
        int targetLevel,
        vector<int>& v
    ) {

        if (root == NULL)
            return;

        // We reached the required level
        if (currLevel == targetLevel) {
            v.push_back(root->val);
            return;
        }

        // Go to next level
        nthlevel(root->left, currLevel + 1, targetLevel, v);
        nthlevel(root->right, currLevel + 1, targetLevel, v);
    }

    void lorder(TreeNode* root, vector<vector<int>>& ans) {

        // Find total number of levels
        int n = levels(root);

        // Collect every level one by one
        for (int i = 1; i <= n; i++) {

            vector<int> v;

            // Collect nodes of level i
            nthlevel(root, 1, i, v);

            ans.push_back(v);
        }
    }

    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        lorder(root, ans);

        return ans;
    }
};