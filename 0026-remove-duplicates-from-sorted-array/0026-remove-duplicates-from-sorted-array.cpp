class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int n=arr.size();
        vector<int>ans;
        ans.push_back(arr[0]);
        for(int i=1; i<n; i++){
            if(arr[i]!=arr[i-1]) ans.push_back(arr[i]);

        }
        //copy back into origional array
        for(int i=0; i<ans.size(); i++){
            arr[i]=ans[i];
        }
        return ans.size();
    }
};