class Solution {
public:
    string minRemoveToMakeValid(string s) {

        // Stores indices of unmatched opening brackets '('
        stack<int> st;

        // Marks characters that should be removed
        vector<bool> remove(s.size(), false);

        // Traverse the string
        for (int i = 0; i < s.size(); i++) {

            // Current character is an opening bracket
            if (s[i] == '(') {

                // Store its index
                st.push(i);
            }

            // Current character is a closing bracket
            else if (s[i] == ')') {

                // Matching '(' exists
                if (!st.empty()) {

                    // Match found, remove from stack
                    st.pop();
                }

                // No matching '(' available
                else {

                    // Mark this ')' for removal
                    remove[i] = true;
                }
            }
        }

        // Remaining '(' in stack are unmatched
        while (!st.empty()) {

            // Mark them for removal
            remove[st.top()] = true;

            st.pop();
        }

        // Build the final valid string
        string ans = "";

        for (int i = 0; i < s.size(); i++) {

            // Skip characters marked for removal
            if (!remove[i])
                ans += s[i];
        }

        return ans;
    }
};