class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for(char ch : s) {

            // Push opening brackets
            if(ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }
            else {

                // Closing bracket found but stack is empty
                if(st.empty()) {
                    return false;
                }

                // Check matching brackets
                if(ch == ')' && st.top() != '(') {
                    return false;
                }

                if(ch == '}' && st.top() != '{') {
                    return false;
                }

                if(ch == ']' && st.top() != '[') {
                    return false;
                }

                // Matching pair found, remove opening bracket
                st.pop();
            }
        }

        // Stack must be empty for a valid string
        return st.empty();
    }
};