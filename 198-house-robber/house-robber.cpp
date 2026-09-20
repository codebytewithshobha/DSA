class Solution {
public:
    int solve(int i, vector<int>& nums, vector<int>& dp) {
        
        // Base case
        if (i >= nums.size())
            return 0;

        // Already calculated
        if (dp[i] != -1)
            return dp[i];

        // Rob current house
        int rob = nums[i] + solve(i + 2, nums, dp);

        // Skip current house
        int skip = solve(i + 1, nums, dp);

        // Store and return maximum
        return dp[i] = max(rob, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, -1);

        return solve(0, nums, dp);
    }
};