class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& arr) {
        int n =arr.size();
        int mxm;
        int count=0;
        for(int i=0; i<n; i++){
            if(arr[i]==1){
                count++;
                mxm=max(mxm,count);
            }
            else count=0;
        }
        return mxm;
    }
};