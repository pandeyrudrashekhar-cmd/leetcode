class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        // Step 1: Sort according to start time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        // Step 2: Add first interval
        ans.push_back(intervals[0]);

        // Step 3: Process remaining intervals
        for(int i = 1; i < intervals.size(); i++) {

            int currentStart = intervals[i][0];
            int currentEnd   = intervals[i][1];

            int lastEnd = ans.back()[1];

            // Overlap
            if(currentStart <= lastEnd) {

                // Extend the end of merged interval
                ans.back()[1] = max(lastEnd, currentEnd);
            }
            else {

                // No overlap
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};