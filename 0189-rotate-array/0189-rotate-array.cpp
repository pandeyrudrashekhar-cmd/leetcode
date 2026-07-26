class Solution {
public:
    void rotate(vector<int>& arr, int k) {
        int n=arr.size();
        k=k%n;
        reverse(arr.begin(),arr.end());
        //reverse 1st part
        reverse(arr.begin(),arr.begin()+k);
        //reverse rem whole part
        reverse(arr.begin()+k,arr.end());

    }
};