class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        for(char ch : s){
            if(st.empty()) st.push(ch);
            else if(st.top()==ch) st.pop();
            else{
                st.push(ch);
            }
        }
        //stack stores ans in rev order so first we extract it and then reverse it
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        //reverswe
        reverse(ans.begin(),ans.end());
        return ans;
    }
};