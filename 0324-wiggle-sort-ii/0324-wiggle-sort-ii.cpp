class Solution {
public:
    void wiggleSort(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        vector<int>ans(n);
        int left=(n-1)/2;
        int right=n-1;
        //fill even indices with smaller half
        for(int i=0; i<n; i+=2){
            ans[i]=arr[left];
            left--;
        }
    //fill odd indices
    for(int i=1; i<n; i+=2){
        ans[i]=arr[right];
        right--;
    }
    arr=ans;
        }
};