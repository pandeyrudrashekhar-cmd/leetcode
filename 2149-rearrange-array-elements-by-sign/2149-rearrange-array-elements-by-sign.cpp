class Solution {
public:
    vector<int> rearrangeArray(vector<int>& arr) {
        vector<int>ans,pos,neg;
        int n=arr.size();
        for(int i=0; i<n; i++){
            if(arr[i]>0) pos.push_back(arr[i]);
            else neg.push_back(arr[i]);
        }
        int i=0;
        int j=0;
        while(i<pos.size() && j<neg.size()){
            ans.push_back(pos[i++]);
            ans.push_back(neg[j++]);
        }
        if(i<pos.size()) ans.push_back(pos[i++]);
        if(j<neg.size()) ans.push_back(neg[j++]);
        return ans;

    }
};