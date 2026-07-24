class Solution {
public:
    int majorityElement(vector<int>& nums) {
       map<int,int>freq;
       int n=nums.size();
       for(int i=0;i<nums.size();i++){
        freq[nums[i]]++;
       }
       for(auto it: freq){
        if(it.second>n/2){
            return it.first;
        }
       }
       return -1;
    }
};