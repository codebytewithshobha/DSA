class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Place each value x at index x-1 (if 1 <= x <= n)
        for (int i = 0; i < n; i++) {
            while (nums[i] > 0 && nums[i] <= n
                   && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // Step 2: First index where value != index + 1 gives the answer
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        // Step 3: All of 1..n are present
        return n + 1;
    }
};