class Solution {
public:
    bool canJump(vector<int>& nums) {

        int farthest = 0;

        for (int i = 0; i < nums.size(); i++) {

            // Current index is unreachable
            if (i > farthest)
                return false;

            // Update the farthest index we can reach
            farthest = max(farthest, i + nums[i]);
        }

        return true;
    }
};