class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n=arr.size();
        int totalsum=n*(n+1)/2;
        int Sum=0;
        for(int i=0; i<n; i++){
            Sum+=arr[i];
        }
        return totalsum-Sum;


    }
};