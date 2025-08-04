
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {}; // no digits → no combinations

        vector<string> mapping = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> result;
        string current;
        backtrack(digits, mapping, 0, current, result);
        return result;
    }

private:
    void backtrack(const string &digits, const vector<string> &mapping,
                   int index, string &current, vector<string> &result) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        int digit = digits[index] - '0';
        for (char c : mapping[digit]) {
            current.push_back(c);
            backtrack(digits, mapping, index + 1, current, result);
            current.pop_back(); // backtrack
        }
    }
};

