class Solution {
public:
    void solve(const string& digits, int index, string& output,
               const vector<string>& mapping, vector<string>& ans) {
        // base case: built a full combination
        if (index >= digits.size()) {
            ans.push_back(output);
            return;
        }

        int num = digits[index] - '0';
        const string& value = mapping[num];

        for (char ch : value) {
            output.push_back(ch);                     // choose
            solve(digits, index + 1, output, mapping, ans);  // explore
            output.pop_back();                        // undo (backtrack)
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.empty()) return ans;

        vector<string> mapping = {"", "", "abc", "def", "ghi",
                                  "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string output;
        solve(digits, 0, output, mapping, ans);
        return ans;
    }
};