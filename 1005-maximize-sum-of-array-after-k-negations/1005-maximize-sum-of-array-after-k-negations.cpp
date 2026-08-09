class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        //convert +ve into -ve
        for(int i=0; i<n && k>0 ; i++){
            if(nums[i]<0){
                nums[i]=-nums[i];
                k--;
            }
        }
        //if odd operations are still remaining then flip smallest element
        if(k%2==1) {
            int idx=min_element(nums.begin(),nums.end())-nums.begin();
            nums[idx]=-nums[idx];

        }
        //calculate the sum
        
        int sum=0;
        for(int x:nums){
            sum+=x;
        }
        
        return sum;
    }
};