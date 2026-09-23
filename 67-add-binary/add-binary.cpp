class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;

        string ans = "";

        while (i >= 0 || j >= 0 || carry) {

            int digitA = (i >= 0) ? a[i] - '0' : 0;
            int digitB = (j >= 0) ? b[j] - '0' : 0;

            int sum = digitA + digitB + carry;

            ans += (sum % 2) + '0';

            carry = sum / 2;

            i--;
            j--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};