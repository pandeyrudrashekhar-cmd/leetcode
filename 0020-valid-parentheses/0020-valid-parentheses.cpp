class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(char ch:s){
            //if opening bracket push it into stack
            if(ch=='(' || ch=='{' || ch=='[') st.push(ch);
            else{//closing bracket found
            if(st.empty()) return false;
            if(ch==')' && st.top()!='(') return false;
            if(ch=='}' && st.top()!='{') return false;
            if(ch==']' && st.top()!='[') return false;
            //opening bracket found
            st.pop();


            }
        }
        return st.empty();
    }
};