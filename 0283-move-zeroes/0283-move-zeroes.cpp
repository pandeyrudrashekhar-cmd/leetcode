class Solution {
public:
    void moveZeroes(vector<int>& arr) {
       vector<int>ans;
       for(int i=0; i<arr.size(); i++){
        if(arr[i]!=0) ans.push_back(arr[i]);
       } 
       while(ans.size()<arr.size()){
        ans.push_back(0);
       }
       arr=ans;
    }
};