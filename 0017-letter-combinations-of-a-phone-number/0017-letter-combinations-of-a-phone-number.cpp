class Solution {
public:
    vector<string> ans;
    string keypad[10] = {"",    "",    "abc",  "def", "ghi",
                         "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void solve(int idx, string& digits, string& curr) {
        if (idx == digits.size()) {
            ans.push_back(curr);
            return;
        }
        // get the letters corresponding to this digit
        string letters = keypad[digits[idx] - '0'];
        for (char ch : letters) {
            //choose a letter
            curr.push_back(ch);
            //process next digit
            solve(idx + 1, digits, curr);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {

        if (digits.empty())
            return ans;

        string current;
        solve(0, digits, current);

        return ans;
    }
};