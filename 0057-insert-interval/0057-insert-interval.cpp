class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {

        // Step 1: Insert the new interval
        intervals.push_back(newInterval);

        // Step 2: Sort according to start time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;

        // Step 3: Merge intervals
        for (auto &interval : intervals) {

            if (result.empty() || interval[0] > result.back()[1]) {
                result.push_back(interval);
            }
            else {
                result.back()[1] = max(result.back()[1], interval[1]);
            }
        }

        return result;
    }
};