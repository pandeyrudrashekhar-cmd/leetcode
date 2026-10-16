class Solution {
public:
//check whether it is palindrome or not
vector<vector<string>>ans;
bool ispal(string &s, int l, int r){
    while(l<r){
        if(s[l]!=s[r]){
            return false;
        }
        l++;
        r--;
    }
    return true;
}
void solve(int start, string &s, vector<string>& curr){
    if(start==s.size()){
        ans.push_back(curr);
        return;
    }
    //try every possible ending index
    for(int end=start; end<s.size(); end++){
        if(!ispal(s,start,end)) continue;
        curr.push_back(s.substr(start,end-start+1));
        solve(end+1,s,curr);
        curr.pop_back();
    }
}
    vector<vector<string>> partition(string s) {
        vector<string>curr;
        solve(0,s,curr);
        return ans;
    }
};