class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int start = 0, maxLen = 1;

        auto expandFromCenter = [&](int left, int right) {
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                if (right - left + 1 > maxLen) {
                    start = left;
                    maxLen = right - left + 1;
                }
                --left;
                ++right;
            }
        };

        for (int i = 0; i < s.length(); ++i) {
            expandFromCenter(i, i);     // Odd length palindrome
            expandFromCenter(i, i + 1); // Even length palindrome
        }

        return s.substr(start, maxLen);

        
    }
};