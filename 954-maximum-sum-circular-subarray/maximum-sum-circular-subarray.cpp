class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int totalSum = 0;

        int currentMax = 0;
        int maxSum = INT_MIN;

        int currentMin = 0;
        int minSum = INT_MAX;

        for (int x : nums) {

            // Maximum subarray
            currentMax = max(x, currentMax + x);
            maxSum = max(maxSum, currentMax);

            // Minimum subarray
            currentMin = min(x, currentMin + x);
            minSum = min(minSum, currentMin);

            // Total
            totalSum += x;
        }

        // All numbers are negative
        if (totalSum == minSum)
            return maxSum;

        // Maximum circular subarray
        return max(maxSum, totalSum - minSum);
    }
};