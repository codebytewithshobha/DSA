 #include <numeric> // Required for partial_sum
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        // Modifies nums in-place to store the prefix/running sum
        partial_sum(nums.begin(), nums.end(), nums.begin());
        return nums;
    }
};