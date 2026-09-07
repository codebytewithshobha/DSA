class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1000000007;

        long long dp = 1;   // empty subsequence

        vector<long long> last(26, 0);

        for (char ch : s) {
            int index = ch - 'a';

            long long newDp = (2 * dp - last[index] + MOD) % MOD;

            last[index] = dp;

            dp = newDp;
        }

        // Remove empty subsequence
        return (dp - 1 + MOD) % MOD;
    }
};
