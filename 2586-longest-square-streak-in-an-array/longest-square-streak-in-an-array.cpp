class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<long long> st(nums.begin(), nums.end());

        int ans = -1;

        for (long long x : nums) {
            int len = 1;

            while (x * x <= 10000000000LL &&
                   st.count(x * x)) {
                x = x * x;
                len++;
            }

            if (len >= 2) {
                ans = max(ans, len);
            }
        }

        return ans;
    }
};