class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       //we will sort it according to start time
       sort(intervals.begin(),intervals.end());

       vector<vector<int>>result;
       //add the 1st element int0 result
       result.push_back(intervals[0]);
       for(int i=1; i<intervals.size(); i++){
        //get the last interval that is already present in result
        vector<int>& last=result.back();
        //check if curr interval overlaps
        if(intervals[i][0]<=last[1]){
            //merge interval
            last[1]=max(last[1],intervals[i][1]);
        }
        else{
            result.push_back(intervals[i]);
        }
       }
       return result;

    }
};