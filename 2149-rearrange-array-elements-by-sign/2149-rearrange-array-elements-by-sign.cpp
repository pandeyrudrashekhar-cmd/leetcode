class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // make 3 vector pos, neg and ans vector
        // if no>0 pos then mei push else neg mei push
        // interleave pehle pos mei push then neg mei push
        // add all remaing into ans vector
        // return ans vector
       vector<int>pos,neg,ans;
       int n=nums.size();
       for(int i=0; i<n; i++){
        if(nums[i]>0) pos.push_back(nums[i]);
        else neg.push_back(nums[i]);
       }
       //interleave
       int i=0,j=0;
       while(i<pos.size() && j<neg.size()){
        ans.push_back(pos[i++]);
        ans.push_back(neg[j++]);
       }
       //add remaining elements
       if(i<pos.size()) ans.push_back(pos[i++]);
       if(j<neg.size()) ans.push_back(neg[j++]);
       return ans;
    }
};