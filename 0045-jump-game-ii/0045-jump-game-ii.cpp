class Solution {
public:
    int jump(vector<int>& nums) {

        int jumps = 0;
        int currentEnd = 0;
        int farthest = 0;

        // No need to process last index
        for (int i = 0; i < nums.size() - 1; i++) {

            // Maximum index reachable from current jump range
            farthest = max(farthest, i + nums[i]);

            // Current jump ends here
            if (i == currentEnd) {

                jumps++;
                currentEnd = farthest;
            }
        }

        return jumps;
    }
};