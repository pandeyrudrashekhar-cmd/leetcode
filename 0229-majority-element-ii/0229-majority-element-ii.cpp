class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        map<int,int>freq;
       int n=nums.size();
       for(int i=0;i<nums.size();i++){
        freq[nums[i]]++;
       }
       vector<int>ans;
       for(auto it: freq){
        
        int element=it.first;
        int freq=it.second;
        if(it.second>n/3){
           ans.push_back(element) ;
        }
       }
       return ans;
    }
};