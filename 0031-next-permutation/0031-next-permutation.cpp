class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        // //find the pivot means from where array starts decreasing
        // //find next greater element than pivot, if found then swap them
        // reverse the right part after pivot index
        int n=arr.size();
        int pivot=-1;
        for(int i=n-2; i>=0; i--){
            if(arr[i]<arr[i+1]){
                pivot=i;
                break;
            }
        }
        if(pivot!=-1){
            for(int i=n-1; i>pivot; i--){
                if(arr[i]>arr[pivot]){
                    swap(arr[i],arr[pivot]);
                    break;
                }
            }
        }
        reverse(arr.begin()+pivot+1,arr.end());
    }

};