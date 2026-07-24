class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //boyer more algo
        int candidate=0;
        int count=0;
        for(int i=0; i<nums.size(); i++){
            //if count becomes zero then choose new candidate
            if(count==0) candidate=nums[i];
            //if current element matches camdidate then increase count
            if(nums[i]==candidate) count++;
            else{
                count--;
            }
        }
        return candidate;
    }
};