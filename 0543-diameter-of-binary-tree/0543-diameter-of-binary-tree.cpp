class Solution {
public:

    int diameter = 0;

    int height(TreeNode* root) {

        if (root == NULL)
            return 0;

        // Height of left subtree
        int left = height(root->left);

        // Height of right subtree
        int right = height(root->right);

        // Longest path passing through current node
        diameter = max(diameter, left + right);

        // Return height to parent
        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {

        height(root);

        return diameter;
    }
};