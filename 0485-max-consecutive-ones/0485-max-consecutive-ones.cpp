class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& arr) {
        int n=arr.size();
        int cnt=0;
        int mxm;
        for(int i=0; i<n; i++){
            if(arr[i]==1){
                cnt++;
                mxm=max(mxm,cnt);
            }
            else cnt=0;
        } 
        return mxm;
    }
};