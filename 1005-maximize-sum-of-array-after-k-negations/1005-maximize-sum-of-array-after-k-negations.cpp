class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        //convert -ve no to positive if(k>0)
        for(int i=0; i<n && k>0; i++){
            if(nums[i]<0){
                nums[i]=-nums[i];
                k--;
            }
        }
        //if odd operations are still remaining
        if(k%2==1){
            int idx=min_element(nums.begin(),nums.end())-nums.begin();
            nums[idx]=-nums[idx];
        }
        //calculate sum
        int sum=0;
        for(int x: nums){
            sum+=x;
        }
        return sum;
    }
};