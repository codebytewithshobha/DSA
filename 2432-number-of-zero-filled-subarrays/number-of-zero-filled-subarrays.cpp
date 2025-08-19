class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long result = 0, streak = 0;

        for (int num : nums) {
            if (num == 0) {
                streak++;
                result += streak; // each new zero extends previous subarrays
            } else {
                streak = 0; // reset streak
            }
        }

        return result;
    }
        
};