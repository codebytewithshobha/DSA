class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Always binary search on the smaller array
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size(), n = nums2.size();
        int low = 0, high = m;
        int half = (m + n + 1) / 2;   // size of the combined left half

        while (low <= high) {
            int i = low + (high - low) / 2;   // elements taken from nums1's left
            int j = half - i;                  // elements taken from nums2's left

            int L1 = (i == 0) ? INT_MIN : nums1[i - 1];
            int R1 = (i == m) ? INT_MAX : nums1[i];
            int L2 = (j == 0) ? INT_MIN : nums2[j - 1];
            int R2 = (j == n) ? INT_MAX : nums2[j];

            if (L1 <= R2 && L2 <= R1) {
                // Correct partition found
                if ((m + n) % 2 == 1) return max(L1, L2);
                return (max(L1, L2) + min(R1, R2)) / 2.0;
            }
            else if (L1 > R2) high = i - 1;   // took too many from nums1
            else              low  = i + 1;   // took too few from nums1
        }
        return 0.0;   // unreachable for valid input
    }
};