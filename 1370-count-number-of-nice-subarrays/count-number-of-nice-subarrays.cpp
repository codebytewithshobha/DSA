class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
         return atMost(nums, k) - atMost(nums, k - 1);
    }

private:
    int atMost(vector<int>& nums, int k) {
        if (k < 0) return 0;
        int l = 0, count = 0, oddCount = 0;

        for (int r = 0; r < nums.size(); r++) {
            if (nums[r] % 2 != 0) oddCount++;
            while (oddCount > k) {
                if (nums[l] % 2 != 0) oddCount--;
                l++;
            }
            // All subarrays ending at r with start index in [l..r]
            count += (r - l + 1);
        }
        return count;
        
    }
};