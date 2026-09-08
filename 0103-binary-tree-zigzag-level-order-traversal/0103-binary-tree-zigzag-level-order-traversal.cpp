class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        // Queue is used for level order traversal
        queue<TreeNode*> q;

        // If tree is empty
        if (root == NULL)
            return ans;

        // Start with root
        q.push(root);

        // First level will be Left -> Right
        bool leftToRight = true;

        while (!q.empty()) {

            // Number of nodes in current level
            int size = q.size();

            // Create vector for current level
            vector<int> level(size);

            // Process all nodes of current level
            for (int i = 0; i < size; i++) {

                // Get front node
                TreeNode* curr = q.front();
                q.pop();

                // Decide where to put the current value
                if (leftToRight) {

                    // Normal order
                    level[i] = curr->val;

                } else {

                    // Reverse order
                    level[size - 1 - i] = curr->val;
                }

                // Add left child for next level
                if (curr->left != NULL)
                    q.push(curr->left);

                // Add right child for next level
                if (curr->right != NULL)
                    q.push(curr->right);
            }

            // Add current level to answer
            ans.push_back(level);

            // Change direction for next level
            leftToRight = !leftToRight;
        }

        return ans;
    }
};