class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int i=0;
        for(int j=i+1; j<n; j++){
            if(arr[i]!=arr[j]){
                i++;
                //j++;
                arr[i]=arr[j];
            }
           // j++;
        }
        return i+1;
    }
};