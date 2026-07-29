class Solution {
public:

    void generate(vector<string>& ans,
                  string& s,
                  int open,
                  int close,
                  int n)
    {
        // Base Case
        if(close == n)
        {
            ans.push_back(s);
            return;
        }

        // Choose '('
        if(open < n)
        {
            s.push_back('(');

            generate(ans, s, open + 1, close, n);

            // Backtrack (Undo)
            s.pop_back();
        }

        // Choose ')'
        if(close < open)
        {
            s.push_back(')');

            generate(ans, s, open, close + 1, n);

            // Backtrack (Undo)
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        string s = "";

        generate(ans, s, 0, 0, n);

        return ans;
    }
};