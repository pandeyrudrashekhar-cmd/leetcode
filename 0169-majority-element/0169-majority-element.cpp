class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //using map
       int n=nums.size();
       map<int,int>freq;
       for(int num: nums){
        freq[num]++;
        if(freq[num]>n/2) return num;
       } 
       return -1;
    }
};